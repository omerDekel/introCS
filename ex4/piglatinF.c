/******************************************
*Student name: Omer Dekel
*Student ID: 
*Course Exercise Group: 01
*Exercise name: Exercise 4
******************************************/

#include "piglatinF.h"
#define MAX_SIZE 52
#define WORD_SIZE 19

/****************************************************
		* function name: PigLatin()
		* input: void
		* output: void
		* operation function: the function calls the function TranSentence,
		  that translates sentence, then asks the user if to translate
		  another one in do while loop and if the answer is yes , does it again.
		* *********************************************/

void PigLatin()
{
    char answ;
    do
    {
        TranSentence();
        printf("\n");
        printf("Do you want to translate another sentence?(y/n)\n");
        scanf(" %c",&answ);
    }while (answ=='y');
}

/****************************************************
		* function name: TranSentence
		* input: void
		* output: void
		* operation function: the function gets a sentence and translate it to
		  into pig latin language
		* *********************************************/

void TranSentence()
{
    char *token,dummy;
    char word1[WORD_SIZE]={0};
    char sentence [MAX_SIZE]={0};
    int lenSen;
    printf("Please enter a sentence in English:\n");
    //gets \n to dummy
    scanf("%c",&dummy);
    fgets(sentence,MAX_SIZE,stdin);
    lenSen=strlen(sentence);
    // deleting the '\n' in the char sentence []
    sentence[lenSen-1] = '\0';
    // transfer the word to lower case
    TolowStr(sentence,lenSen);
    //takes a word from the sentence
    token=strtok(sentence," \t\n");
    while (token != NULL)
    {
        //copy the word took from the sentence to word1
        strcpy(word1,token);
        TransWorld(word1);
        //takes a word from the sentence
        token=strtok(NULL," \t\n");
    }
}

/****************************************************
		* function name: TolowStr
		* input: char str [MAX_SIZE],int lenSt
		* output: void
		* operation function: the function gets a char array
		  and its length, then changes it to lower case
		* *********************************************/

void TolowStr(char str [MAX_SIZE],int lenSt)
{
int i;
for(i=0;i<lenSt;i++)
    str[i]=tolower(str[i]);
}

/****************************************************
		* function name: TransWorld
		* input: char word1 [WORD_SIZE]
		* output: int
		* operation function: the function gets a char array
          (the world token from the sentence) and
          translate it to Pig Latin language
		* *********************************************/

void TransWorld(char word1[WORD_SIZE])
{
    int len=strlen(word1);
    //char array for consonants
    char conos[WORD_SIZE]={0};
    // char array for the rest letters
    char rest [WORD_SIZE]={0};
    int i=0;
    int j=0;
    // if the world starts with a vowel letter
    if ((word1[0]=='a')||(word1[0]=='e')||(word1[0]=='i')
        ||(word1[0]=='o')||(word1[0]=='u'))
    {
        // adding it "way"
        strcat(word1,"way");
        printf("%s ",word1);
    }
    // in case all the word with consonant
    else if ((CheckAllCons (word1,len))==1)
    {
        // adding "ay" to this world
        strcat(word1,"ay");
        printf("%s ",word1);
    }
    // if the world starts with consonant but not all of that are consonants
    else
    {
        //put the first letter to the consonant array
        conos[i]=word1[i];
        i++;
        // put the others consonants letter to the consonants array
        while((word1[i]!='a')&&(word1[i]!='e')&&(word1[i]!='i')
              &&(word1[i]!='o')&&(word1[i]!='u')&&(word1[i]!='y'))
        {
            conos[i]=word1[i];
            i++;
        }
        //adding "ay" to word in this word
        strcat(conos,"ay");
        for(;i<len;i++,j++)
            //puts all the other letters in array
            rest[j]=word1[i];
        rest[j]='\0';
        // attaching the two strings to one
        strcat(rest,conos);
        printf("%s ",rest);
    }
}

/****************************************************
		* function name: CheckAllCons
		* input: char word1 [WORD_SIZE],int len
		* output:  return 1 if all the letters there are consonant, else 0;
		* operation function: the function gets a char array
		  checks in for loop if a letter in this word is consonant
          and counts the amount of the consonants,
		  then check if it's equal to the length of the word.
		* *********************************************/

int CheckAllCons (char word1 [WORD_SIZE],int len)
{
    int i;
    //counter of the consonants
    int count=0;
    for (i=0; i<len;i++)
    {
        if ((word1[i]!='a')&&(word1[i]!='e')&&(word1[i]!='i')
              &&(word1[i]!='o')&&(word1[i]!='u')&&(word1[i]!='y'))
            count++;
    }
    if (count==len)
        return 1;
    return 0;
}
