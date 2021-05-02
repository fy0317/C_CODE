#include<stdio.h>
#include"game.h"
	//两个数组初始化数组的实现，char board[ROWS][COLS]接收mine数组和show数组
	//这里设置一个字符set接收mine和show数组传参过来的‘0’和‘*’
void Initboard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <=col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void Setmine(char mine[ROWS][COLS], int row, int col)
{
	int count = SETCOUNT;	//为了灵活变通，可以自己设置布置雷的个数，在头文件中自定义个数
	while (count)
	{	//直到count为0才退出循环，并且每次都是随机坐标布置雷，count是几，x和y就要随机几次
		int x = rand() % row + 1;//用户输入的坐标的范围就是行数列数的范围，应该是row+1才是正确的坐标范围
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
static int  get_mine_count(char mine[ROWS][COLS], int x,int y)
{

	return mine[x][y - 1] +
		mine[x - 1][y - 1] +
		mine[x + 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y + 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y] - 8 * '0';

}

int get_showblank(char mine[ROWS][COLS], char show[ROWS][COLS], int x , int y)
{
	
	int count_mine = get_mine_count(mine, x,y);
	//*****************************
	int count_blank = 0;  //要加一个static修饰

	//*****************************
	//不能用while循环
	//while(count_mine == 0)

	if (count_mine == 0)
	{
		show[x][y] = ' ';
		count_blank++; 
		if (x - 1 >= 1 && x - 1 <= ROW && y >= 1 && y <= COL && show[x - 1][y] == '*')
		{
			count_blank += get_showblank(mine, show, x - 1, y);

		}
		if (x >= 1 && x <= ROW && y - 1 >= 1 && y - 1 <= COL && show[x][y - 1] == '*')
		{
			count_blank += get_showblank(mine, show, x, y - 1);

		}
		if (x + 1 >= 1 && x + 1 <= ROW && y >= 1 && y <= COL && show[x + 1][y] == '*')
		{
			count_blank += get_showblank(mine, show, x + 1, y);

		}
		if (x >= 1 && x <= ROW && y + 1 >= 1 && y + 1 <= COL && show[x][y + 1] == '*')
		{
			count_blank += get_showblank(mine, show, x, y + 1);
		}
	}
	//*****************************
	//增加一个else，如果周围有雷，将show[x][y]置为雷的数目，并且count_blank也要加1
	else
	{
		count_blank++;
		show[x][y] = count_mine + '0';
	}
	return count_blank;	
}
void Findmine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;//记录不是雷的个数
	while (win < row * col - SETCOUNT)
	{
		int count_blank = 0;
		Displayboard(mine, row, col);
 		printf("请输入排查雷的坐标：\n");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)		//判断坐标合法性
		{
			if (mine[x][y] == '1')		//遍历到了雷
			{
				printf("很遗憾，你被炸死了！\n");
				Displayboard(mine, row, col);
				break;
			}
			else
			{
				int count_mine = get_mine_count(mine, x, y);
				if (count_mine == 0 && show[x][y] == '*')
				{
					//*****************************
					//返回值要接收
					count_blank = get_showblank(mine, show, x, y);		//统计展开了多少空白
					//get_showblank(mine, show, x, y);
					win += count_blank;
				}
				else if(show[x][y] == '*')
				{
					show[x][y] = count_mine + '0';
					win++;
				}
				Displayboard(show, row, col);
				
			}
		}
		else
		{
			printf("坐标不合法，请重新输入！\n");
		}
	}
	if (win == row * col - SETCOUNT)
	{
		printf("恭喜你，排雷成功！\n");
		Displayboard(show, row, col);
	}

		
}
