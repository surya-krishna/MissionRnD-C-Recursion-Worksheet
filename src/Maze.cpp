/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.
maze[3][5] = {
{ 1, 0, 0, 0, 1 },
{ 1, 1, 0, 1, 1 },
{ 0, 1, 1, 1, 0 }

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
#include<malloc.h>
int path_check(int row, int column, int x1, int y1, int x2, int y2,int *maze)
{
	
	if (x1 == x2&&y1 == y2)
		return 1;
	if (x1 - 1>=0 && *((maze + (x1-1)*column) + y1) == 0)
		path_check(row, column, x1 - 1, y1, x2, y2, maze);
	if (y1 - 1>=0 && *((maze + x1*column) + (y1-1)) == 0)
		path_check(row, column, x1, y1 - 1, x2, y2, maze);
	if (x1 + 1<=row&&*((maze + (x1+1)*column) + y1) == 0)
		path_check(row, column, x1 + 1, y1, x2, y2, maze);
	if (y1 + 1<=column&&*((maze + x1*column) + (y1+1)) == 0)
		path_check(row, column, x1, y1 + 1, x2, y2, maze);

return 0;
}

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int check = path_check(rows, columns, x1, y1, x2, y2,maze);
	if (check==1)
	return 1;
	
	return 0;
}
