#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("***************************************\n");
	printf("***************************************\n");
	printf("***********                 ***********\n");
	printf("***********   1->��ʼ��Ϸ   ***********\n");
	printf("***********   0->������Ϸ   ***********\n");
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
			printf("��С��\n");
		else if (n > num)
			printf("�´���\n");
		else
		{
			printf("��ϲ�㣬������!\n");
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
			printf("~~~~~~~~~��Ϸ��ʼ~~~~~~~~~~~ \n");
			playgame();
			break;
		case 0:
			printf("~~~~~~~~~��Ϸ����~~~~~~~~~~~ \n");
			break;
		default:
			printf("�����������������: \n");
			break;
		}

	} while (n);
	return 0;
}