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

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
#include"cstdbool"
bool check(int *a, int x, int y, int x2, int y2, int len)
{
	if (x >= 0 && y >= 0 && *((a + x*len) + y) == 1)
		return true;

	return false;
}
bool mazerecur(int *a, int x, int y, int x2, int y2, int flg, int len)
{
	if (x == x2  && y == y2)
	{
		return true;
	}
	if (check(a, x, y, x2, y2, len) == true)
	{
		if (flg != 1)
		{
			if (mazerecur(a, x + 1, y, x2, y2, flg, len) == true)
				return true;
			if (mazerecur(a, x, y + 1, x2, y2, flg, len) == true)
				return true;
			flg = 1;
		}
		if (mazerecur(a, x - 1, y, x2, y2, flg, len) == true)
		{
			return true;
		}
		if (mazerecur(a, x - 1, y + 1, x2, y2, flg, len) == true)
			return true;
		return false;
	}
	return false;
}
bool diagcheck(int *maze, int rows, int columns, int x2, int y2)
{
	int i = 0, j = 0, count = 0;
	if (rows > 0)
	{
		for (;;)
		{
			if (*((maze + i*columns) + j) == 1)
				count += 1;
			i = i + 1;
			j = j + 1;
			if ((i == x2&&j == y2) || (j == columns))
				break;
		}
		if (count == rows)
			return false;
		else
			return true;
	}
	else 
		return true;
}
int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (rows >= 0 && columns >= 0 && 1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0&&(*((maze+x2*columns)+y2)==1))
	{
			bool t = mazerecur(maze, x1, y1, x2, y2, 0, columns);
			if (t)
				return 1;
			else
				return 0;
			return 1;
	}
	return 0;
}
