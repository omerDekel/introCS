/******************************************
*Student name: Omer Dekel
*Student ID: 
*Course Exercise Group: 01
*Exercise name: Exercise 5
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "onetofourF.h"
#include "taskfiveF.h"
#include "queueF.h"
int main()
{
    int input;
	do
    {
        printf("Please enter your input:\n");
        scanf("%d",&input);
        switch(input)
        {
            case 1:TaskOne();
                break;
            case 2: TaskTwo();
                break;
            case 3:TaskThree();
                break;
            case 4:TaskFour();
                break;
            case 5:TaskFive();
                break;
            case 6:QueueF();
                break;
            case 0:
                break;
            default: printf("Error: Illegal input\n");
                break;
        }
    }while (input!=0);
	return 0;
}
