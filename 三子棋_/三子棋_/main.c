#define _CRT_SECURE_NO_WARNINGS
#include"game.h"


void menu()
{
	printf("**********************************************\n");
	printf("********请选择->   1:开始游戏  0：结束游戏\n");
	printf("**********************************************\n");
}
void game()
{
	char arr[ROW][COL] = { 0 };
	//InitBoard(arr, ROW, COL);					//初始化棋盘
	PrintBoard(arr, ROW, COL);					//打印棋盘
	while (1)
	{
		char ret = 0;
		PlayerMove(arr, ROW, COL);
		PrintBoard(arr, ROW, COL);					//打印棋盘
		ret = IsWin(arr, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("玩家赢了\n");
			}
			else if (ret == '#')
			{
				printf("电脑赢了\n");
			}
			else
			{
				printf("平局\n");
			}
			break;
		}
		CopMove(arr, ROW, COL);
		PrintBoard(arr, ROW, COL);
		ret = IsWin(arr, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("玩家赢了\n");
			}
			else if (ret == '#')
			{
				printf("电脑赢了\n");
			}
			else
			{
				printf("平局\n");
			}
			break;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}