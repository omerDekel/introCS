/******************************************
*Student name: Omer Dekel
*Course Exercise Group: 01
*Exercise name: Exercise 5
******************************************/

#ifndef TASKFIVEH_H_INCLUDED
#define TASKFIVEH_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_SIZE 30
void TaskFive();
void SortStr(char **wordsArr, int wordsNum);
void SwapCharPtr(char** str, int i, int j);
void PrintArr(char **wordsArr, int wordsNum);
int CheckIfThere(char** str,char* name, int wordsNum);
#endif // TASKFIVEH_H_INCLUDED
