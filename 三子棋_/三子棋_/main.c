#define _CRT_SECURE_NO_WARNINGS
#include"game.h"


void menu()
{
	printf("**********************************************\n");
	printf("********��ѡ��->   1:��ʼ��Ϸ  0��������Ϸ\n");
	printf("**********************************************\n");
}
void game()
{
	char arr[ROW][COL] = { 0 };
	//InitBoard(arr, ROW, COL);					//��ʼ������
	PrintBoard(arr, ROW, COL);					//��ӡ����
	while (1)
	{
		char ret = 0;
		PlayerMove(arr, ROW, COL);
		PrintBoard(arr, ROW, COL);					//��ӡ����
		ret = IsWin(arr, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("���Ӯ��\n");
			}
			else if (ret == '#')
			{
				printf("����Ӯ��\n");
			}
			else
			{
				printf("ƽ��\n");
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
				printf("���Ӯ��\n");
			}
			else if (ret == '#')
			{
				printf("����Ӯ��\n");
			}
			else
			{
				printf("ƽ��\n");
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
		printf("��ѡ��:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}