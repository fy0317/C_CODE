#define _CRT_SECURE_NO_WARNINGS
#include "ShowBoard.h"
void ShowBoard(char arr[Row][Lin], int row, int lin)  //显示当前棋盘的内容
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lin; j++)
		{
			printf(" %c ", arr[i][j]);
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < lin; j++)
				printf("----");
			printf("\n");
		}
	}
}