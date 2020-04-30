/******************************************
*Student name: Omer Dekel
*Course Exercise Group: 01
*Exercise name: Exercise 4
******************************************/

#include "matrixF.h"

/****************************************************
		* function name: CalculatorMatrix
		* input: void
		* output: void
		* operation function: the function gets sizes of the dimensions of
		 the first matrix, checks if normal. if not, asks again.
         after gets the elements of this matrix, and then
		 calls the function OperatrMenu.
		* *********************************************/

void CalculatorMatrix()
{
    int row, col;
    //array saves the values of the dimensions of the matrix we"ll swap
    int dimenMat[2];
    int mat[SIZE][SIZE];
    printf("Welcome to the Matrix calculator\n");
    printf("Please enter first matrix dimensions (row col):\n");
    scanf("%d %d",&row,&col);
    // checks if the dimensions are normal
    if (row<1 || col<1)
    {
        printf("Error\n");
        printf("Please enter first matrix dimensions (row col):\n");
        scanf("%d %d",&row,&col);
    }
    BuildMat(mat,row,col);
    OperatrMenu(mat,row,col,dimenMat);
}
/****************************************************
		* function name: BuildMat
		* input: int mat[SIZE][SIZE],int row,int col
		* output: void
		* operation function: this function asks for the elements
		  of the matrix, and puts them in the matrix it gets, with
		  a for loop , according to the values of the column and the row
		  it gets.
		* *********************************************/

void BuildMat(int newMat[SIZE][SIZE],int row,int col)
{
    int i,j;
    printf("Please enter matrix elements(%dx%d):\n",row,col);
    for (i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            scanf("%d",&newMat[i][j]);
    }
}

/****************************************************
		* function name: OperatrMenu
		* input: int mat[SIZE][SIZE],int row,int col,int dimenMat[2]
		* output: void
		* operation function: this function make the operation action
		 according to the operator it gets.
		* *********************************************/

void OperatrMenu(int mat[SIZE][SIZE],int row,int col,int dimenMat[2])
{
    // the operator
    char oper;
    do
    {
        printf("Please enter operation:(+,-,*,t,c,q)\n");
        scanf (" %c",&oper);
        switch (oper)
        {
        // for input '+' in variable oper make addition with another matrix
        case '+': AddingMatrix(mat,row,col);
            break;
        // for input '-' in variable oper make subtract with another matrix
        case '-': SubtractMatrix(mat,row,col);
            break;
        // for '*' multiply the matrix in another one
        case '*': MultipicationMatrix(mat, row, col,dimenMat);
            //variable col gets the value of the col of the multiplication matrix
            col=dimenMat[1];
            break;
        // for 't' make transpose to the matrix
        case 't': TransposMatrix(mat,row,col,dimenMat);

            /*

             variables row and col gets the sizes of
             dimensions of transpose matrix saved on the array dimenMat

             */

            row=dimenMat[0];
            col=dimenMat[1];
            break;
        // for 'c' clear the calculator. building a new matrix .
        case 'c':  printf("Please enter first matrix dimensions (row col):\n");
            scanf("%d %d",&row,&col);
            // checks if the dimensions are normal
            if (row<1 || col<1)
            {
                printf("Error\n");
                printf("Please enter first matrix dimensions (row col):\n");
                scanf("%d %d",&row,&col);
            }
            BuildMat(mat,row,col);
            break;
        // for 'q' quit the program
        case 'q': break;
        //for any other input
        default: printf("This operation does not exist!\n");
            break;
        }
    //end of while loop
    }while (oper!='q');
}

/****************************************************
		* function name: AddingMatrix
		* input: int mat[SIZE][SIZE],int row,int col
		* output: void
		* operation function: this function asks for the elements
		  of the second matrix. Then adds them with the elements
		  in the main matrix and calls the function
          PrintMatrix that print this matrix.
		* *********************************************/

void AddingMatrix(int mat[SIZE][SIZE],int row,int col)
{
    int i,j;
    int mat2[row][col];
    printf("Please enter matrix elements(%dx%d):\n",row,col);
    for (i=0; i<row; ++i)
    {
        for (j=0; j<col; ++j)
        {
            scanf("%d",&mat2[i][j]);
            // puts the sum in the first matrix
            mat[i][j]=mat2[i][j]+mat[i][j];
        }
    }
    printf ("The answer is:\n");
    // call a function that prints the matrix
    PrintMatrix(mat,row,col);
}

/****************************************************
		* function name: PrintMatrix
		* input: int mat[SIZE][SIZE],int row,int col
		* output: void
		* operation function: this function gets a matrix,
		  the sizes of its row and column, and prints this matrix.
		* *********************************************/

void PrintMatrix(int mat[SIZE][SIZE],int row, int col)
{
    int i,j;
    for (i=0; i<row; ++i)
    {
        for (j=0; j<col; ++j)
            printf("%4d",mat[i][j]);
        printf("\n");
    }
}

/****************************************************
		* function name: SubtractMatrix
		* input: int mat[SIZE][SIZE],int row,int col
		* output: void
		* operation function: this function asks for the elements
		  of the second matrix and subtracts them with the elements in
          main matrix and call the function PrintMatrix
          that prints this matrix.
		* *********************************************/

void SubtractMatrix(int mat[SIZE][SIZE],int row,int col)
{
    int i,j;
    int mat2[row][col];
    printf("Please enter matrix elements(%dx%d):\n",row,col);
    for (i=0; i<row; ++i)
    {
        for (j=0; j<col; ++j)
        {
            scanf("%d",&mat2[i][j]);
            //puts the subtraction of the first matrix and second in the first matrix
            mat[i][j]=mat[i][j]-mat2[i][j];
        }
    }
    printf ("The answer is:\n");
    // calls another function that prints the matrix
    PrintMatrix(mat,row,col);
}

/****************************************************
		* function name: MultipicationMatrix
		* input: int mat[SIZE][SIZE],int row,int col,int dimenMat[2]
		* output: void
		* operation function: builds the second matrix,
		  calculates the multiplication of the main matrix
          with the second one, and put the values of the multiplication
          in new matrix.
		* *********************************************/

void MultipicationMatrix( int mat[SIZE][SIZE],int row,int col,int dimenMat[2])
{
    int i,j;
    int a;
    int secMat[SIZE][SIZE];
    int matMulti[SIZE][SIZE];
    int dimen;
    // the value col of the first matrix is the row in the second one
    int row2=col;
    printf("Please enter column dimension of second matrix:\n");
    scanf("%d",&dimen);
    //checks if the value of column dimension is not normal
    if (dimen<1)
    {
    printf("Error\n");
    printf("Please enter column dimension of second matrix:\n");
    scanf("%d",&dimen);
    }
    //builds the second matrix
    BuildMat(secMat,row2,dimen);
    for (i=0;i<row;i++)
    {

    /*

    calculates the sum of the multiplication elements of the row
    from the first matrix in the column of the second matrix

    */

        for (j=0;j<dimen;j++)
        {
            int sum=0;
            for (a=0;a<row2;a++)
                //multiply the main matrix with the second one
               sum=(mat[i][a]*secMat[a][j])+sum;
            // puts the value of the sum in cell in new matrix
            matMulti[i][j]=sum;
        }
    }
    printf("The answer is:\n");
    PrintMatrix(matMulti,row,dimen);
    // put the elements of the multiplication matrix in the main matrix
    SwapMat(mat,row,col,matMulti,row,dimen);

    /*

    saves the value of the column dimension of second matrix- the column
    of the multiplication matrix

    */

    dimenMat[1]=dimen;
}

/****************************************************
 * function name: TransposMatrix
 * input: int mat[SIZE][SIZE],int row,int col,int dimenMat[2]
 * output: void
 * operation function:in this function we build the transpose
   matrix of the matrix, prints it and then saves the dimensions of this matrix
   of the array to use it in main calculator matrix function.
 * *********************************************/

void TransposMatrix(int mat[SIZE][SIZE] ,int row,int col,int dimenMat[2])
{
    int tranMat[SIZE][SIZE];
    int i,j;
    // build the transpose matrix
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
            tranMat[j][i]=mat[i][j];
    }
    printf("The answer is:\n");
    PrintMatrix(tranMat,col,row);
    //call function that swaps the elements between the matrix
    SwapMat(mat,row,col,tranMat,col,row);
    // saving the new dimensions
    dimenMat[0]=col;
    dimenMat[1]=row;
}

/****************************************************
		* function name: SwapMat
		* input: (int mat[SIZE][SIZE],int row,int col,
          int secMat[SIZE][SIZE],int row2,int col2)
		* output: void
		* operation function:this function puts the elements
          from the matrix secMat in the mat
        * *********************************************/

void SwapMat(int mat[SIZE][SIZE],int row,int col,
            int secMat[SIZE][SIZE],int row2,int col2)
{
    int i,j;
    //nullifying the main matrix
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            mat[i][j]=0;
    }
    //swaping between the matrix
    for(i=0;i<row2;i++)
    {
        for(j=0;j<col2;j++)
            mat[i][j]=secMat[i][j];
    }
}
