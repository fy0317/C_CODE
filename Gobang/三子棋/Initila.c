#define _CRT_SECURE_NO_WARNINGS
#include"ShowBoard.h"

void InitialBoard(char Board[Row][Lin], int row, int lin)  //将棋盘初始化，使其全为' '
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lin; j++)
		{
			Board[i][j] = ' ';
		}
	}
}