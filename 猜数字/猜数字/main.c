#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("***************************************\n");
	printf("***************************************\n");
	printf("***********                 ***********\n");
	printf("***********   1->开始游戏   ***********\n");
	printf("***********   0->结束游戏   ***********\n");
	printf("***********                 ***********\n");
	printf("***************************************\n");
	printf("***************************************\n");

}
void playgame ( )
{
	int num = 0;
	int n = 0;
	num = rand() % 100 + 1;
	printf("%d\n", num);
	while (0)
	{
		scanf("%d", &n);
		if (n < num)
			printf("猜小了\n");
		else if (n > num)
			printf("猜大了\n");
		else
		{
			printf("恭喜你，猜中了!\n");
			break;
		}
	}
}
int main()
{
	int n = 0;
	srand((unsigned int)time(NULL));

	do 
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("~~~~~~~~~游戏开始~~~~~~~~~~~ \n");
			playgame();
			break;
		case 0:
			printf("~~~~~~~~~游戏结束~~~~~~~~~~~ \n");
			break;
		default:
			printf("输入错误，请重新输入: \n");
			break;
		}

	} while (n);
	return 0;
}