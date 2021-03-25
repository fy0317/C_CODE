#define _CRT_SECURE_NO_WARNINGS
#include"ShowBoard.h"
#include"Initial.h"
#include"Play.h"
int main()

{
	char arr[Row][Lin] = { 0 };  
	InitialBoard(arr, Row, Lin);//初始化棋盘
	int n;
	//先让用户选择是否开始游戏
	printf("**********************************************\n");
	printf("********请选择->   1:开始游戏  2：结束游戏\n");
	printf("**********************************************\n");
	scanf("%d", &n);
	srand((unsigned int)time(NULL));
	while (1)
	{
		if (n == 1)   //玩家输入1，开始游戏
		{
			begin :
			printf("游戏开始->\n");
			ShowBoard(arr, Row, Lin);  //显示棋盘
			Play(arr, Row, Lin);   //游戏过程
			break;
		}
		else if (n == 2)
		{
			printf("确定要结束游戏么？1->确认退出   2->继续游戏\n");
			int m;
		again:
			scanf("%d", &m);
			if (m == 1)
				break;
			else if (m == 2)
				goto begin;
			else
			{
				printf("输入错误，请重新输入\n");
				goto again;
			}
		}
		else 
		{
			printf("选择错误，请重新输入");
			scanf("%d", &n);
		}
	}
	srand((unsigned)time(NULL));
	return 0;
}
