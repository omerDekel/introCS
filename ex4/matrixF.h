/******************************************
*Student name: Omer Dekel

*Course Exercise Group: 01
*Exercise name: Exercise 4
******************************************/

#ifndef MATRIXF_H_INCLUDED
#define MATRIXF_H_INCLUDED
#include <stdio.h>
#define SIZE 15
void CalculatorMatrix();
void AddingMatrix(int mat[SIZE][SIZE],int row,int col);
void SubtractMatrix(int mat[SIZE][SIZE],int row,int col);
void MultipicationMatrix(int mat[SIZE][SIZE],int row,int col,int dimenMat[2]);
void BuildMat(int newMat[SIZE][SIZE],int row,int col);
void TransposMatrix(int mat[SIZE][SIZE] ,int row,int col,int dimenMat[2]);
void PrintMatrix(int mat[SIZE][SIZE],int row,int col);
void SwapMat(int mat[SIZE][SIZE],int row,int col
            ,int Secmat[SIZE][SIZE],int row2,int col2);
void OperatrMenu(int mat[SIZE][SIZE],int row,int col,int dimenMat[2]);
#endif // MATRIXF_H_INCLUDED
