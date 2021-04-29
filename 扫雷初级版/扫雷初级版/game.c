#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void InitBoard(char board[ROWS][COLS], int row, int col, char c)	//初始化棋盘
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = c;
	}
}
void PrintBoard(char board[ROWS][COLS], int row, int col)			//打印棋盘 
{
	printf("  ");
	for (int i = 1; i < row - 1; i++)			//打印列坐标
		printf("%d ", i);
	printf("\n");
	for (int i = 1; i < row - 1; i++)
	{
		printf("%d ", i);			//打印横坐标
		for (int j = 1; j < col - 1; j++)
			printf("%c ", board[i][j]);
		printf("\n");
	}

}
void SetBoard(char board[ROWS][COLS], int row, int col)		//布雷
{
	for (int cnt = 0; cnt < COUNT;)
	{
		int x = rand() % row + 1;		//随机产生横纵坐标
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			cnt++;
		}
	}
}
int Num(char board[ROWS][COLS], int x, int y)			//统计当前位置周围有几个雷
{
	return board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] +
		board[x][y - 1] + board[x][y + 1] +
		board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] - 8 * '0';
}
void FindBoard(char board[ROWS][COLS], char ShowBoard[ROWS][COLS], int row, int col)			//排雷
{
	int x = 0;
	int y = 0;
	int cnt = ROW * COL - COUNT;		//cnt表示非雷的数目，即棋盘大小减去地雷数
	while (1)
	{
		printf("请输入坐标\n");
		scanf("%d%d", &x, &y);
		if (x < 1 || x >row || y < 1 || y > col)
		{
			printf("坐标非法，请重新输入\n");
		}
		else
		{
			if (board[x][y] == '1')			//当前坐标位置是雷，游戏结束
			{
				printf("你失败了，游戏结束\n");
				PrintBoard(board, row, col);
				break;
			}
			else if (board[x][y] == '0')		//当前坐标不是雷，统计周围雷的数目
			{
				if (0 == Num(board, x, y))		//如果周围没有雷，则当其置为空
				{
					ShowBoard[x][y] = ' ';
				}
				else ShowBoard[x][y] = Num(board, x, y) + '0';  //周围有雷，将其置为雷的个数
																//（因为我们打印的是字符型变量，因此要加上'0'才是所对应的数字字符）
				cnt--;						//每排完一个雷，非雷的数目减1
				PrintBoard(ShowBoard, row, col);		//打印当前显示棋盘的信息
			}
		}
		if (cnt == 0)		//所有非雷位置均排查完
		{
			printf("恭喜你，成功排雷\n");
			PrintBoard(board, row, col);
			break;
		}
	}
}