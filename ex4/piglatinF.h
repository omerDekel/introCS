/******************************************
*Student name: Omer Dekel
*Student ID: 
*Course Exercise Group: 01
*Exercise name: Exercise 4
******************************************/

#ifndef PIGLATINF_H_INCLUDED
#define PIGLATINF_H_INCLUDED
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 52
#define WORD_SIZE 19
void PigLatin();
void TranSentence();
void TransWorld(char word1[WORD_SIZE]);
void TolowStr(char str [MAX_SIZE],int lenSt);
int CheckAllCons (char word1 [WORD_SIZE] ,int len);
#endif // PIGLATINF_H_INCLUDED
