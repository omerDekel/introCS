/******************************************
*Student name: Omer Dekel
*Course Exercise Group: 01
*Exercise name: Exercise 5
******************************************/

#ifndef QUEUEF_H_INCLUDED
#define QUEUEF_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void QueueF();
void PrintMenu();
void Push(int num,int *in,int *out,int ***fifo);
int Pop(int *pNum,int *in,int *out,int ***fifo);
void PrintQueue(int *in,int *out,int ***fifo);
int Max(int *in,int *out,int ***fifo);
int Min(int *in,int *out,int ***fifo);
void Index(int num,int *in,int *out,int ***fifo);
void Clear(int *in,int *out,int ***fifo);
#endif // QUEUEF_H_INCLUDED
