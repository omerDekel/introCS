/******************************************
*Student name: Omer Dekel
*Course Exercise Group: 01
*Exercise name: Exercise 5
******************************************/

#include "queueF.h"

/******************************************************
    * function name: void QueueF
    * input: void
    * output: void
    * operation function: the function creats a linked list queue
      when out is the index of the first element that will get
      out from the list, "in" points the index of next number
      that will be added. Then function does actions according
      to the choices in the menu that user chose.
* *******************************************************/

void QueueF()
{
    int **fifo = NULL;
    int in = 0, out = 0;
    int selectNum;
    int isExit = 0;
    int num;
    printf("Please select your choice:\n");
    PrintMenu();
    while (! isExit)
    {
        scanf("%d", &selectNum);
        switch (selectNum)
        {
        case 0:
            isExit = 1;
            break;
        case 1:
            printf("Enter item value to add\n");
            scanf("%d", &num);
            Push(num,&in,&out,&fifo);
            printf("Item %d added\n", num);
            printf("Please select your next choice (select 8 for complete menu)\n");
            break;
        case 2:
            if (Pop(&num,&in,&out,&fifo))
                printf("Item %d was removed\n", num);
            printf("Please select your next choice (select 8 for complete menu)\n");
            break;
        case 3:
            if (out >= in)
                printf ("Error: Queue is empty!\n");
            else
                PrintQueue(&in,&out,&fifo);
            printf("Please select your next choice (select 8 for complete menu)\n");
            break;
        case 4:
            if (out >= in)
                printf ("Error: Queue is empty!\n");
            else
            {
                num = Max(&in,&out,&fifo);
                printf ("Maximum item in queue is %d\n", num);
            }
            printf("Please select your next choice (select 8 for complete menu)\n");
            break;
        case 5:
            if (out >= in)
                printf ("Error: Queue is empty!\n");
            else
            {
                num=Min(&in,&out,&fifo);
                printf ("Minimum item in queue is %d\n", num);
            }
            printf("Please select your next choice (select 8 for complete menu)\n");
            break;
        case 6:
            if (out >= in)
                printf ("Error: Queue is empty!\n");
            else
            {
                printf("Please enter the item you would like to know its index\n");
                scanf("%d", &num);
                Index(num,&in,&out,&fifo);
            }
            printf("Please select your next choice (select 8 for complete menu)\n");
            break;
        case 7:
            Clear(&in,&out,&fifo);
            printf("Queue is clear\n");
            printf("Please select your next choice (select 8 for complete menu)\n");
            break;
        case 8:
            PrintMenu();
            break;
        default:
            printf("Error: Unrecognized choice\n");
            printf("Please select your next choice (select 8 for complete menu)\n");
            break;
        }
    }//end of while loop
    return ;
}

/******************************************************
    * function name: PrintMenu
    * input: void
    * output: void
    * operation function: this function prints all the choices in the menu.
* *******************************************************/

void PrintMenu()
{
    printf("0.Exit\n");
    printf("1.Add item to the queue\n");
    printf("2.Remove item from the queue\n");
    printf("3.Print queue\n");
    printf("4.Print the maximum item in the queue\n");
    printf("5.Print the minimum item in the queue\n");
    printf("6.Print index of given item\n");
    printf("7.Clear queue\n");
    printf("8.Print the menu\n");
}

/******************************************************
    * function name: Push
    * input: int *pNum, int *in, int *out, int ***fifo
    * output: void
    * operation function: the function adds the num to the queue
      fifo and then Increases in one the index in so
      "in" points the index of next number
      that will be added.
* *******************************************************/

void Push(int num, int *in, int *out, int ***fifo)
{
	int fifoSize = *in - *out + 1;
	*fifo = (int **)realloc(*fifo, sizeof(int *)* fifoSize);
	if (*fifo == NULL)
	{
		printf("Error: Insufficient Memory\n");
		return;
	}
	(*fifo)[*in] = (int *)malloc(sizeof(int));
	if ((*fifo)[*in] == NULL)
	{
		printf("Error: Insufficient Memory\n");
		return;
	}
	*((*fifo)[*in]) = num;
	*in = (*in) + 1;
}

/******************************************************
    * function name: Pop
    * input: int *pNum, int *in, int *out, int ***fifo
    * output: returns 0 if the queue is empty, if we took out a number
      from the queue ,it returns 1
    * operation function: the function takes out
     the number in index out (the first number in the queue).
* *******************************************************/

int Pop(int *pNum, int *in, int *out, int ***fifo)
{
	//if queue is empty
	if (*out >= *in)
	{
		printf("Error: Queue is empty!\n");
		free(*fifo);
		*in = 0;
		*out = 0;
        *fifo = NULL;
		return 0;
	}
	*pNum = *((*fifo)[*out]);
	free(*fifo[*out]);
	*out = (*out) + 1;
	return 1;
}

/******************************************************
    * function name: PrintQueue
    * input: int *in, int *out, int ***fifo
    * output: void
    * operation function: the function go all over
    the queue by for loop and prints every number.
* *******************************************************/

void PrintQueue(int *in, int *out, int ***fifo)
{
	int i;
	printf("Queue items are: ");
	for (i = *out; i < *in; i++)
		printf("%d ", *((*fifo)[i]));
    printf("\n");
}

/******************************************************
    * function name: Max
    * input: int *in, int *out, int ***fifo
    * output: returns the maximum number in the queue
    * operation function: the function checks which number is bigger
     in the queue by for loop from the first number to the end.
* *******************************************************/

int Max(int *in, int *out, int ***fifo)
{
	int i;
	int maxNum = *((*fifo)[*out]);
	for (i = (*out) + 1; i < *in; i++)
	{
		if (*((*fifo)[i]) > maxNum)
			maxNum = *(*fifo)[i];
	}
	return maxNum;
}

/******************************************************
    * function name: Min
    * input: int *in, int *out, int ***fifo
    * output: return the smaller number in the queue
    * operation function: the function checks which number is smaller
     in the queue by for loop from the first number to the end.
* *******************************************************/

int Min(int *in, int *out, int ***fifo)
{
	int i;
	int minNum = *(*fifo)[*out];
	for (i = *out + 1; i < *in; i++)
	{
		if (*(*fifo)[i] < minNum)
			minNum = *(*fifo)[i];
	}
	return minNum;
}

/******************************************************
    * function name: Index
    * input: int num,int *in,int *out,int ***fifo
    * output: void
    * operation function: the function gets int num,int *in,int *out,int ***fifo
     and prints the index of num in the queue.
* *******************************************************/

void Index(int num,int *in,int *out,int ***fifo)
{
    int found=0;
    int i ;
    for(i=*out; i<*in ; i++)
    {
		if (*(*fifo)[i] == num)
        {
            printf ("Item %d index is %d\n", num, i+1);
            found=1;
        }
    }
    if (!found)
        printf("Error: no such item!\n");
    return;
}

/******************************************************
    * function name: Clear
    * input: int *in, int *out, int ***fifo
    * output: void
    * operation function: the function free every allocation of queue
      and the queue itself.
* *******************************************************/

void Clear(int *in, int *out, int ***fifo)
{
    int i;
    if (*out >= *in)
        printf("Error: Queue is empty!n");
    else
    {
        for (i = *out; i < *in; i++)
            free((*fifo)[i]);
        free(*fifo);
        *in = 0;
        *out = 0;
        *fifo = NULL;
    }
}
