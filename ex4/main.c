/******************************************
*Student name: Omer Dekel
*Student ID: 
*Course Exercise Group: 01
*Exercise name: Exercise 4
******************************************/

#include <stdio.h>
#include <string.h>
#include "matrixF.h"
#include "piglatinF.h"

/*

start of main
the program gets a string from the user
if the string is "Calculator" it will run Matrix Calculator function
if its Translator it will run PigLatin Translator function,if its "quit"
it will stop the program run,else error message and back to the start

*/

int main()
{
    int len;
    int calculator,translator,quit;
    char line[WORD_SIZE];
    do
    {
    printf("Main menu, choose between the options:\n");
    printf("Matrix Calculator\n");
    printf("PigLatin Translator\n");
    scanf(" %s",line);
    len=strlen(line);
    //changes the word to lower case
    TolowStr(line,len);
    //if the word that was received is calculator,the variable is 0
    calculator=strcmp(line,"calculator");
    //if the word that was received is translator,the variable is 0
    translator=strcmp(line,"translator");
    //if the word that was received is quit,the variable is 0
    quit=strcmp(line,"quit");
    //checking which of the word were chosen
    if(calculator==0)
        CalculatorMatrix();
    else if (translator==0)
        PigLatin();
    else if (quit==0)
        return 0;
    //in case of any other word
    else
        printf("This was not an option.\n");
    }while (quit!=0);
   return 0;
}
