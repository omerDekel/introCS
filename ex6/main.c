/******************************************
*Student name: Omer Dekel
*Course Exercise Group: 01
*Exercise name: Exercise 6
******************************************/

#include "gadt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_STRING_SIZE 16

typedef struct point_s
{
	int x, y;
} point_t;

/****************************************************
		* function name: create_elm_point
		* input: void
		* output: ELM
		* operation function: the function allocates by malloc
		to the struct point, return the pointer to the allocation
		* *********************************************/

ELM create_elm_point()
{
	point_t *p1 = (point_t *)malloc(sizeof(struct point_s));
	return (void *)p1;
}

/****************************************************
		* function name: cpy_elm_point
		* input: ELM p1, ELM p2
		* output: void
		* operation function: the function copies the x value
		in the p2 to the x vale of p1,and the y value of p2
		to the y value of p1.
		* *********************************************/

void cpy_elm_point(ELM p1, ELM p2)
{
	((point_t *)p1)->x = ((point_t*)p2)->x;
	((point_t *)p1)->y = ((point_t*)p2)->y;
}

/****************************************************
		* function name: cmp_elm_point
		* input: ELM p1, ELM p2
		* output: returns 0 if p1 equal to p2, 1 if bigger, -1
		if p1 is less then p2
		* operation function: the function calculates the distance of p1
		and of p2, and checks if they are equal.
		* *********************************************/

int cmp_elm_point(ELM p1, ELM p2)
{
	int d1, d2;
	//calculates the distance of p1 and p2
	d1 = abs(((point_t *)p1)->x) + abs(((point_t *)p1)->y);
	d2 = abs(((point_t *)p2)->x) + abs(((point_t *)p2)->y);
	if (d1 > d2)
		return 1;
    else if (d1 == d2)
		return 0;
	else
		return -1;
}

/****************************************************
		* function name: free_elm_point
		* input: ELM p
		* output: void
		* operation function: the function frees the malloc of p
		* *********************************************/

void free_elm_point(ELM p)
{
	free((point_t *)p);
}

/****************************************************
		* function name: print_elm_point
		* input: ELM p
		* output: void
		* operation function: the function prints the point,
		with three zeros, before x and y, seperated by '|'.
		* *********************************************/

void print_elm_point(ELM p)
{
	printf("%.3d|%.3d\n", ((point_t *)p)->x, ((point_t *)p)->y);
}

/****************************************************
		* function name: add_elm_to_elm_point
		* input: ELM p1, ELM p2
		* output: ELM (pointer to p1)
		* operation function: the function adds the x value of p1
		 with the x value of p2 ans adds the y value of p1 with p2.
		* *********************************************/

ELM add_elm_to_elm_point(ELM p1, ELM p2)
{
	((point_t *)p1)->x = ((point_t *)p1)->x + ((point_t *)p2)->x;
	((point_t *)p1)->y = ((point_t *)p1)->y + ((point_t *)p2)->y;
	return p1;
}

/****************************************************
		* function name: create_elm_str
		* input: void
		* output: ELM pointer to str
		* operation function: the function allocates by
		malloc memory to string str.
		* *********************************************/

ELM create_elm_str()
{
	char *str = (char *)malloc(MAX_STRING_SIZE);
	return (void *)str;
}

/****************************************************
		* function name: cpy_elm_str
		* input: ELM str1, ELM str2
		* output: void
		* operation function: the function copies the string
		in the str2 to the str1.
		* *********************************************/

void cpy_elm_str(ELM str1, ELM str2)
{
	strcpy((char *)str1, (char *)str2);
}

/****************************************************
		* function name: cmp_elm_str
		* input: ELM str1, ELM str2
		* output: returns 0 if str1 equal to str2, 1 if bigger, -1
		if str1 is less then str2
		* operation function: the function calculates the distance of p1
		and of p2, and checks if they are equal.
		* *********************************************/

int cmp_elm_str(ELM str1, ELM str2)
{
	return strcmp((char *)str1, (char *)str2);
}

/****************************************************
		* function name: free_elm_str
		* input: ELM str
		* output: void
		* operation function: the function frees the malloc of str
		* *********************************************/

void free_elm_str(ELM str)
{
	free((char *)str);
}

/****************************************************
		* function name: print_elm_str
		* input: ELM str
		* output: void
		* operation function: the function prints the string str.
		* *********************************************/

void print_elm_str(ELM str)
{
    //casting str from ELM to char* before printing
	printf("%s\n", (char *)str);
}

/****************************************************
		* function name: add_elm_to_elm_str
		* input: ELM str1, ELM str2
		* output: ELM (pointer to str1)
		* operation function: the function appends the string pointed
		to by str1 to the end of the string pointed to by str2.
		* *********************************************/

ELM add_elm_to_elm_str(ELM str1, ELM str2)
{
	strcat((char *)str1, (char *)str2);
	return str1;
}

int main()
{
	int isPoint;
	void *pnt;
	void *pnt1;
	point_t dot;
	point_t dot1;
	char inputChar = ' ';
	char str[MAX_STRING_SIZE];
	char str1[MAX_STRING_SIZE];
	HEAD head;
	//the user selects the node type, 0 for string,1 for point
	scanf("%d ", &isPoint);
	if (!isPoint)
	{
		scanf("%s", str);
		//creating the head in string type list
		head = SLCreate((ELM)str, create_elm_str, cpy_elm_str, cmp_elm_str
                        , free_elm_str, print_elm_str, add_elm_to_elm_str);
	}
	else
	{
		scanf(" (%d,%d)", &(dot.x), &(dot.y));
		//creating the head in point type list
		head = SLCreate((ELM)&dot, create_elm_point, cpy_elm_point,
                        cmp_elm_point, free_elm_point,
                        print_elm_point, add_elm_to_elm_point);
	}
	//upon failure of allocating
	if (head == NULL)
		return -1;
	while (inputChar != 'e')
	{
		scanf("%c", &inputChar);
			switch(inputChar)
			{
            //for input 'a' from the user we adding a new node
			case 'a':
				if (!isPoint)
				{
					scanf("%s", str);
					//casting str from char* to void*
					pnt = (void *)str;
				}
				else
				{
                    scanf(" (%d,%d)", &(dot.x), &(dot.y));
                    //casting &dot from point_t* to void*
					pnt = (void *)(&dot);
				}
				SLAddListElement(&head, pnt);
				break;
            //for input 's' , we searching value from the user in the list
			case 's':
				if (!isPoint)
				{
					scanf("%s", str);
                    //casting str from char* to void*
					pnt = (void *)str;
				}
				else
				{
                    scanf(" (%d,%d)", &(dot.x), &(dot.y));
                    //casting &dot from point_t* to void*
					pnt = (void *)(&dot);
				}
				//if the value we got from the user isn't in the list
				if (SLFindElement(head, pnt) == NULL)
					printf("FALSE\n");
				else
					printf("TRUE\n");
				break;
            //for 'd' we delete a value from the list which requested from the user
			case 'd':
				if (!isPoint)
				{
					scanf("%s", str);
					pnt = (void *)str;
				}
				//if it's string list
				else
				{
                    scanf(" (%d,%d)", &(dot.x), &(dot.y));
					pnt = (void *)(&dot);
				}
				if (SLRemoveElement(&head, pnt) != SUCEESS)
					printf("FALSE\n");
                //in case we delete the single node in the list
				if (SLLength(head) == 0)
					inputChar = 'e';
				break;
            //for input 'p' we print the list
			case 'p':
				SLPrint(head);
				break;
            //for input 'l' we print the length of the list
			case 'l':
				printf("%d\n",SLLength(head));
				break;
            //for input 't':add element from the list to element we get from the user
			case 't':
				if (!isPoint)
				{
					scanf("%s %s", str, str1);
					//casting the two strings to void*
					pnt = (void *)str;
					pnt1 = (void *)str1;
				}
				else
				{
					scanf(" (%d,%d) (%d,%d)", &(dot.x), &(dot.y),
                         &(dot1.x), &(dot1.y));
                    //casting the two points to void*
					pnt = (void *)(&dot);
					pnt1 = (void *)(&dot1);
				}
				SLAddToElement(&head, pnt, pnt1);
				break;
            //for input 'e' we destroy the list and finishing the program
			case 'e':
				SLDestroy(head);
				break;
            default:
                break;
			}
		}//end of while loop
	return 0;
}

