/******************************************
*Student name: Omer Dekel
*Course Exercise Group: 01
*Exercise name: Exercise 5
******************************************/

#include "taskfiveF.h"

/******************************************************
    * function name: TaskFive
    * input: void
    * output: void
    * operation function: the function gets a an unlimited number of names
      from the user, until input "QUIT".Then function prints the names sorted
      alphabetically.
* *******************************************************/

void TaskFive()
{
    char **wordsArr = NULL;
	int wordsNum = 0;
	char str[MAX_WORD_SIZE];
    int stopLoop = 0;
    //variable to count the amount of the names
    int counter=0;
	printf("Please enter list of names:\n");
	scanf("%s", str);
	while (strcmp(str,"QUIT") != 0 && !stopLoop)
	{
		wordsArr = (char **)realloc(wordsArr, (wordsNum + 1) * sizeof (char *));
		if (wordsArr == NULL)
		{
			printf ("Error: Cannot allocate Memory\n");
			stopLoop = 1;
		}
		wordsArr[wordsNum] = (char *)malloc(strlen(str));
		if (wordsArr[wordsNum] == NULL)
		{
			printf ("Error: Cannot allocate Memory\n");
			stopLoop = 1;
		}
		//if the name isn't there
		if ((CheckIfThere(wordsArr,str,wordsNum))==0)
        {
            //copying the name to array of names
            strcpy(wordsArr[wordsNum], str);
            wordsNum++;
        }
        counter++;
		scanf("%s", str);
	}
	printf("There are %d names:\n", counter);
	SortStr(wordsArr, wordsNum);
	PrintArr(wordsArr, wordsNum);
}

/******************************************************
* function name: SortStr
* input: char** str, int i, int j
* output: void
* operation function: Then function sorting the names
  alphabetically.
* *******************************************************/

void SortStr(char **wordsArr, int wordsNum)
{
    int i,j;
    //go over the string
	for (i = 0; i<wordsNum- 1; i++)
	{
		//sorting in bubble sort
		for (j = 0; j<wordsNum - 1 - i; j++)
		{
			if (strcmp(wordsArr[j],wordsArr[j+1])>0)
                SwapCharPtr(wordsArr, j, j + 1);
        }
	}
}

/******************************************************
* function name: SwapCharPtr
* input: char** str, int i, int j
* output: void
* operation function: the function swaps between the char in str[i]
and the char in str[j]
* *******************************************************/

void SwapCharPtr(char** str, int i, int j)
{
	char *tmp;
	tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}

/******************************************************
* function name: CheckIfThere
* input: char** str,char* name, int wordsNum
* output: returns 1 if it's there, else 0.
* operation function: the function checks if the name is allready
  in the array.
* *******************************************************/

int CheckIfThere(char** str,char* name, int wordsNum)
{
    int i;
    for (i=0;i<wordsNum;i++)
    {
        if(strcmp(str[i],name)==0)
            return 1;
    }
    return 0;
}

/******************************************************
* function name: PrintArr
* input: char **wordsArr, int wordsNum
* output: void
* operation function: the function prints all the names
  and then free every allocation of string in the array
  and the array.
* *******************************************************/

void PrintArr(char **wordsArr, int wordsNum)
{
    int i;
    for ( i = 0 ; i < wordsNum; i++)
		printf("%s\n", wordsArr[i]);
    for (i=0;i<wordsNum;i++)
        free(wordsArr[i]);
	free(wordsArr);
	return ;
}
