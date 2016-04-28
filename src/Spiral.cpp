/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9





1 2 3 4 5 6   
7 8 9 0 1 2
3 4 5 6 7 8
9 0 1 2 3 4
5 6 7 8 9 0
1 2 3 4 5 6

00 01 02 03 04 05 
10 11 12 13 14 15
20 21 22 23 24 25
30 31 32 33 34 35
40 41 42 43 44 45
50 51 52 53 54 55

00 01 02 03 04 05 15 25  35 45 55 54 53 52 51 50 40 30 20 10 11 12 13 14 24 34 44











Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
#include<malloc.h>
int spiral_arr(int row_in,int row_fin,int column_in,int column_fin,int **input_array,int row,int column,int *arr,int ind)
{
	arr[ind++] = input_array[row][column];

	if (row_in > row_fin || column_in > column_fin || (column == column_fin&&row_in == row_fin) || (row == row_fin && column_in == column_fin))
		return 0;

	if (column == column_in&&row == row_in-1)
		spiral_arr(row_in++,row_fin--,column_in++,column_fin--,input_array,row_in,column_in,arr,ind);
	else
	if (row==row_in&&column<column_fin)
		spiral_arr(row_in, row_fin, column_in, column_fin, input_array, row, column++, arr, ind);
	else
	if (column == column_fin&&row<row_fin)
		spiral_arr(row_in, row_fin, column_in, column_fin, input_array, row++, column, arr, ind);
	else
	if (row==row_fin&&column>column_in)
		spiral_arr(row_in, row_fin, column_in, column_fin, input_array, row, column--, arr, ind);
	else
	if (column==column_in&&row>row_in)
		spiral_arr(row_in, row_fin, column_in, column_fin, input_array, row--, column, arr, ind);

}

int *spiral(int rows, int columns, int **input_array)
{
	int n = rows*columns;
	int *arr =(int *)malloc(n*sizeof(int));
	spiral_arr(0,rows-1,0,columns-1,input_array,0,0,arr,0);
	return arr;
	return NULL;
}
