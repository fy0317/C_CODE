#include<stdio.h>
#include"game.h"
#include<stdlib.h>
#include<time.h>
void game()
{
	char mine[ROWS][COLS] = { 0 };	//创建存放布置雷的数组
	char show[ROWS][COLS] = { 0 };	//创建存放排查雷的数组
	Initboard(mine, ROWS, COLS,'0');	//初始化布置雷的棋盘，mine表示布置雷数组的首地址
	Initboard(show, ROWS, COLS, '*');	//初始化排查雷的数组，show表示排查雷数组的首地址
	//Displayboard(mine, ROW, COL);	//打印布置雷的棋盘，这里不用打印扩展的两行两列，只需在中间的棋盘布雷，扫雷也同样
	Displayboard(show, ROW, COL);
	Setmine(mine, ROW, COL);	//布置雷
	//Displayboard(mine, ROW, COL);
	Findmine(mine,show, ROW, COL);	//排查雷
}
void menu()
{
	printf("**********************\n");
	printf("******* 1.play *******\n");
	printf("******* 0.exit *******\n");
	printf("**********************\n");
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//用于随机函数rand的调用
	do
	{
		menu();
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("扫雷游戏开始\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新选择！\n");

		}

	} while (input);
	return 0;
}