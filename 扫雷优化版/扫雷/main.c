#include"game.h"
void menu()
{
	printf("**********************************************\n");
	printf("********请选择->   1:开始游戏  0：结束游戏****\n");
	printf("**********************************************\n");
}
void game()
{
	char Myboard[ROWS][COLS] = { 0 };		//用来存放地雷
	char ShowBoard[ROWS][COLS] = { 0 };		//用来显示排雷的信息
	InitBoard(Myboard, ROWS, COLS, '0');	//将地雷棋盘全部初始化为0
	InitBoard(ShowBoard, ROWS, COLS, '*');	//将显示棋盘全部初始化为*
	SetBoard(Myboard, ROW, COL);		//布雷
	PrintBoard(ShowBoard, ROW, COL);		
	FindBoard(Myboard,ShowBoard, ROW, COL);			//排雷
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));		//初始化种子
	do
	{
		menu();		//打印菜单

		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("扫雷游戏开始:\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误,请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}