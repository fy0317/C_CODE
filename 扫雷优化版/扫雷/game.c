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
	for (int i = 1; i <= row  ; i++)			//打印列坐标
		printf("%d ", i);
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);			//打印横坐标
		for (int j = 1; j <= col; j++)
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
int Num(char board[ROWS][COLS],int x,int y)			//统计当前位置周围有几个雷
{
	return board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] +
		board[x][y - 1] + board[x][y + 1] +
		board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] - 8 * '0';		
}
int Blank(char board[ROWS][COLS], char ShowBoard[ROWS][COLS], int x, int y)		//判断当前位置周围是不是没有雷
{
	 int count = 0;		//展开的格子数
	for (int i = x - 1; i <= x + 1 && i >=0 && i <= ROW+1; i++)
	{
		for (int j = y - 1; j <= y + 1 && j >=0 && j <=COL; j++)
		{
			if (i == x && j == y)		//跳过坐标为（x，y）的位置
				;
			else if (ShowBoard[i][j] == '*' && board[i][j] != '1')		//如果坐标(i,j)处没有被初始化并且不为雷，判断其周围有没有雷
			{															//如果周围也没有雷，将其展开	
				int cnt = Num(board, i, j);                                                                               
				if (cnt == 0)
				{
					ShowBoard[i][j] = ' ';
					count += Blank(board, ShowBoard, i, j);				//继续判断这个坐标周围的位置是否需要展开
				}
				else ShowBoard[i][j] = cnt + '0';
				if (i >= 1 && i <= ROW && j >= 1 && j <= COL)		//当展开的格子在有效棋盘范围内时，count++
					count++;
			}
		}
	}
	return count;		//总共展开了多少个格子
}
void FindBoard(char board[ROWS][COLS],char ShowBoard[ROWS][COLS],int row, int col)			//排雷
{
	int cnt = ROW * COL - COUNT;
	int time = 1;		//time为1时表示是第一步
	int over = 0;
	//PrintBoard(board, row, col);
	while (1)		
	{
		printf("请选择-> \n1、排雷   2、标记\n");
		int choose = 0;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			while (1)		//排雷循环
			{
				printf("请输入排雷的坐标\n");
				int x = 0;
				int y = 0;
				scanf("%d%d", &x, &y);
				if (x < 1 || x >row || y < 1 || y > col)
				{
					printf("坐标非法，请重新输入\n");
				}
				else
				{
					if (board[x][y] == '1')
					{
						if (time) //如果第一次就遇见雷,则重置这个雷的位置
						{
							board[x][y] = '0';
							while (1)		//重置第一次雷的位置
							{
								int x1 = rand() % row + 1;
								int y1 = rand() % col + 1;
								if (board[x1][y1] == '0')
								{
									board[x1][y1] = '1';
									break;		//跳出重置第一次雷的循环
								}
							}
							time = 0;	//time置为0表示不是第一次
							if (0 == Num(board, x, y))
							{
								ShowBoard[x][y] = ' ';
							}
							else ShowBoard[x][y] = Num(board, x, y) + '0';
							cnt--;
							int count = Blank(board, ShowBoard, x, y);
							cnt -= count;
							PrintBoard(ShowBoard, row, col);
							goto end;		//第一次排到雷，判断是否排完
						}
						else		//不是第一次
						{
							over = 1;
							break;	//跳出排雷循环
						}
					}
					else if (board[x][y] == '0')
					{
						time = 0;
						if (0 == Num(board, x, y))
						{
							ShowBoard[x][y] = ' ';
						}
						else ShowBoard[x][y] = Num(board, x, y) + '0';
						cnt--;
						int count = Blank(board, ShowBoard, x, y);
 						cnt -= count;
						PrintBoard(ShowBoard, row, col);
						break;		//跳出排雷循环
					}
				}
			}
			break;		//跳出switch
		case 2:
			printf("请输入标记的坐标\n");
			while (1)	//标记循环
			{
				int x1 = 0;
				int y1 = 0;
				scanf("%d%d", &x1, &y1);
				if (x1< 1 || x1>row || y1<1 || y1>col)
					printf("坐标越界，请重新输入\n");
				else if (ShowBoard[x1][y1] != '*')
					printf("此处坐标已排查过,请重新输入\n");
				else if (ShowBoard[x1][y1] == '*')
				{
					ShowBoard[x1][y1] = '#';
					PrintBoard(ShowBoard, row, col);
					break;		//跳出标记循环
				}
			}
			break;		//跳出switch
		default:
			printf("输入错误，请重新输入\n");
			break;	//跳出switch
		}
		end :
		if (over)
		{
			printf("你失败了，游戏结束\n");
			PrintBoard(board, row, col);
			break;		//游戏结束
		}
		if (cnt == 0)
		{
			printf("恭喜你，成功排雷\n");
			PrintBoard(board, row, col);
			break;		//游戏结束
		}
	}
}