#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//初始化棋盘
void InitBoard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++);
}
//打印棋盘
void PrintBoard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
			for (j = 0; j < col; j++)
				printf("---");
		printf("\n");
	}
}

//玩家下棋
void PlayerMove(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("玩家下棋，请输入落子的坐标:\n");
	while (1)
	{
		scanf("%d%d", &i, &j);
		if (i <= 0 || j <= 0 || i > ROW || j > COL)
			printf("坐标输入错误，请重新输入\n");
		else
		{
			if (arr[i - 1][j - 1] == 0) 
			{
				arr[i - 1][j - 1] = '*';
				break;
			}
			else printf("此处已经被占用，请重新输入\n");
		}
	}
}
//电脑下棋
void CopMove(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("电脑下棋:\n");
	while (1)
	{
		i = rand() % row;
		j = rand() % col;
		if (arr[i][j] == 0)
		{
			arr[i][j] = '#';
			break;
		}
	}
}
int IsFull(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			if (arr[i][j] == 0) return 0;
	return 1;
}
char IsWin(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	//判断三行
	for (i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != 0)
		{
			return  arr[i][1];//
		}
	}

	//判断三列
	for (i = 0; i < col; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != 0)
		{
			return arr[1][i];
		}
	}

	//判断对角线
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != 0)
	{
		return arr[1][1];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != 0)
	{
		return arr[1][1];
	}

	//判断平局
	//如果棋盘满了返回1， 不满返回0
	int ret = IsFull(arr, row, col);
	if (ret == 1)
	{
		return 'Q';
	}

	//继续
	return 'C';
}


