/******************************************
*Student name: Omer Dekel
*Student ID: 
*Course Exercise Group: 01
*Exercise name: Exercise 5
******************************************/

#include "onetofourF.h"

/******************************************************
    * function name: TaskOne
    * input: void
    * output: void
    * operation function: the function gets a length of a string and then
      gets a string  in this length, and sorting it as requested.
* *******************************************************/

void TaskOne()
{
	char *p1;
	int size, changed;
	printf("Please enter how many chars to allocate:\n");
	scanf("%d", &size);
	// allocates memory to the size of string
	p1 = (char*)calloc(size, sizeof(char));
	//upon failure of the allocation
	if (p1 == NULL)
	{
		printf("Error: Cannot allocate Memory\n");
		return;
	}
	printf("Allocated %d chars\n", size);
	printf("Please enter string to be sorted:\n");
	scanf("%s", p1);
	//checks if the input is normal
	if (CheckInput(p1)==0)
        printf("Error: Illegal input\n");
    else
    {
        //changed is 1 in case the string was changed
        changed = SortingString(p1);
        if (changed == 1)
            printf("The string after sorting is: %s\n", p1);
        else
            printf("The string is already sorted\n");
        // freeing the allocation
        free(p1);
    }
}

/******************************************************
* function name: SortingString
* input: char* str
* output: void
* operation function: the function gets string str and then
sorts it that the lower case in the beginning of the string
,sorted Alphabetically, and the capital letters at the end
of the string, sorted Alphabetically. If the string
was changed return 1, else 0.
* *******************************************************/

int SortingString(char* str)
{
	int i, j, checkChange = 0;
	//go over the string
	for (i = 0; i<strlen(str) - 1; i++)
	{
		//for each char in the string
		for (j = 0; j<strlen(str) - 1 - i; j++)
		{
			if (str[j] >= 'A'&&str[j] <= 'Z')
			{
				//if chars not sorted - swap
				if ((str[j]>str[j + 1]) || (str[j + 1] >= 'a'&&str[j + 1] <= 'z'))
				{
					checkChange = 1;
					Swap(str, j, j + 1);
				}
			}
			if (str[j] >= 'a'&&str[j] <= 'z')
			{
				if ((str[j + 1] >= 'a'&&str[j + 1] <= 'z') && (str[j] > str[j + 1]))
				{
					checkChange = 1;
					Swap(str, j, j + 1);
				}
			}
		}
	}
	return checkChange;
}

/******************************************************
* function name: Swap
* input: char* str, int i, int j
* output: void
* operation function: the function swaps between the char in str[i]
and the char in str[j]
* *******************************************************/

void Swap(char* str, int i, int j)
{
	int tmp;
	tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}

/******************************************************
* function name: CheckInput
* input: char* str
* output: return 1 if the string str is not normal, else 0
* operation function: the function checks any char in str
  for i=0 to i is less the length of the string if its  not letter,
  if not it's it returns zero, if all the chars letters returns 1
* *******************************************************/

int CheckInput(char* str)
{
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if ((str[i]<'A'||(str[i]>'Z'&&str[i]<'a')||str[i]>'z'))
            return(0);
    }
    return 1;
}

/******************************************************
    * function name: TaskTwo
    * input: void
    * output: void
    * operation function: the function gets lengths of two strings and then
      prints the times a string is a concatenation of another second one.
* *******************************************************/

void TaskTwo()
{
    //the value of the times of concatenation
    int counter;
    char* p1;
    char* p2;
    int size1, size2;
    printf("Please enter how many chars to allocate to the two strings:\n");
    scanf("%d %d",&size1,&size2);
    p1 = (char*)calloc(size1, sizeof(char));
    p2 = (char*)calloc(size2, sizeof(char));
    //upon failure of allocation
    if (p1 == NULL || p2== NULL)
	{
		printf("Error: Cannot allocate Memory\n");
		return;
	}
    printf("Allocated %d chars and %d chars\n", size1,size2);
	printf("Please enter two arrays of chars:\n");
	scanf("%s %s",p1,p2);
	counter=SubGenerator(p1,p2);
	if(counter==0)
        printf("No concatenation found\n");
    else
        printf("%s is a concatenation of %s %d times\n",p1,p2,counter);
    free(p1);
    free(p2);
}

/******************************************************
    * function name: SubGenerator
    * input: char *str,char *sub
    * output: returns the times that sub is a concatenation of str
    * operation function: the function gets two strings and then
      checks in for loop every char from str and sub if they are
      matching to each other that the sub is really sub-string
      of the string str
* *******************************************************/

int SubGenerator(char *str,char *sub)
{
    int count=0;
    int i,j =0;
    //the variable check stops the for loop if sub cant be substring
    int check=1;
    int lenStr=strlen(str);
    //go all over str to the end
    for (i=0;i<lenStr && check != 0 ;i++)
    {
        if (str[i]!=sub[j])
        {
            check=0;
            count=0;
        }
        else
        {
            j++;
            if (j==strlen(sub))
            {
                count++;
                j=0;
            }
        }
    }
    return count;
}

/******************************************************
    * function name: TaskThree
    * input: void
    * output: void
    * operation function: the function gets length of a string and then
      prints the shortest prefix of this string.
* *******************************************************/

void TaskThree()
{
    int lenPref,size;
    char *p1,*pref;
    printf("Please enter how many chars to allocate:\n");
	scanf("%d", &size);
	// allocates memory to the size of string
	p1 = (char*)calloc(size, sizeof(char));
	//upon failure of the allocation
	if (p1 == NULL)
	{
		printf("Error: Cannot allocate Memory\n");
		return;
	}
	printf("Allocated %d chars\n", size);
	printf("Please enter your string:\n");
	scanf("%s",p1);
	lenPref=ShortestStr(p1);
	//if the prefix is the string itself
	if(strlen(p1)==lenPref)
	    pref=p1;
    else
        p1[lenPref]='\0';
    printf("The shortest prefix building the string is: %s of length %d\n",p1
           ,lenPref);
    free(p1);
}

/******************************************************
    * function name: ShortestStr
    * input: char *str
    * output: returns the length of the prefix
    * operation function: the function run all over the string
      in for loop and tries to find the prefix of the string
      (substring) the Divided it if it's not, the prefix
      is the string itself.
* *******************************************************/

int ShortestStr(char *str)
{
    int lenstr;
    int i = 0;
    int j;
    int lenPref = 1;
    lenstr = strlen(str);
    for(j = lenPref; j< lenstr; j++)
    {
        if (str[i]==str[j])
            i++;
        else
        {
            lenPref++;
            i=0;
        }
    }
    // if the sub-string we found is Divided the string
    if (lenstr%lenPref!=0)
        lenPref=lenstr;
    return lenPref;
}

/******************************************************
* function name: TaskFour
* input: void
* output: void
* operation function: the function reads a string size and
  number n . Then reads a string in size of the string size
  and then prints it when the first n words are reversed and
  the else not.
* *******************************************************/

void TaskFour()
{
 	int strSize, n;
	char *str;
    int pStr = 0;
	printf("Please enter how many chars to allocate:\n");
	scanf("%d", &strSize);
	// allocates memory to the size of string
	str = (char*)calloc(strSize, sizeof(char));
	//upon failure of the allocation
	if (str == NULL)
	{
		printf("Error: Cannot allocate Memory\n");
		return;
	}
	printf("Allocated %d chars\n", strSize);
	printf("Please enter your string:\n");
	//getting the words
	while (strlen(str) < strSize)
	{
		scanf("%s", str+pStr);
		pStr = strlen(str);
		//separating the words
		*(str+pStr) = ' ';
		pStr++;
	}
	*(str+ pStr - 1) = '\0';
	printf("Please enter how many words to reverse:\n");
	scanf("%d",&n);
	ReverseNumWords(str, n);
	printf("The string after reverse is: %s\n",str);
	free(str);
	return ;
}


/******************************************************
    * function name: ReverseNumWords
    * input: char *str, int n
    * output: void
    * operation function: the function Receiving The string
     str and the number n.The function will change the string
     str that only n the first words in reverse order, and the rest not
* *******************************************************/

void ReverseNumWords(char *str, int n)
{
    int i;
    char *word;
    char **wordsToReverse;
    int pStr = 0;
	wordsToReverse = (char **)calloc(sizeof(char *), n);
	if (wordsToReverse == NULL)
	{
		printf("Error: Cannot allocate Memory\n");
		return;
	}
	//go from that start og the string to n
	for (i = 0 ; i < n ; i++)
	{
	    //takes the word separate by " "
		word = strtok(str + pStr, " ");
		//allocates a memory to the word
		wordsToReverse[i] = (char *)malloc(strlen(word));
		strcpy(wordsToReverse[i], word);
		pStr += strlen(word)+1;
	}
	pStr = 0;
	//copy the words in reveres to str
	for ( i = n-1 ; i >= 0 ; i--)
	{
		strcpy(str + pStr, wordsToReverse[i]);
		pStr += strlen(wordsToReverse[i]);
		*(str+pStr) = ' ';
		pStr++;
	}
	//freeing the allocations
    for ( i = n-1 ; i >= 0 ; i--)
        free(wordsToReverse[i]);
	free(wordsToReverse);
}
