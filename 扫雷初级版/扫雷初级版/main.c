#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("**********************************************\n");
	printf("********��ѡ��->   1:��ʼ��Ϸ  0��������Ϸ****\n");
	printf("**********************************************\n");
}
void game()
{
	char Myboard[ROWS][COLS] = { 0 };		//������ŵ���
	char ShowBoard[ROWS][COLS] = { 0 };		//������ʾ���׵���Ϣ
	InitBoard(Myboard, ROWS, COLS, '0');	//����������ȫ����ʼ��Ϊ0
	InitBoard(ShowBoard, ROWS, COLS, '*');	//����ʾ����ȫ����ʼ��Ϊ*
	SetBoard(Myboard, ROW, COL);		//����
	PrintBoard(ShowBoard, ROWS, COLS);
	FindBoard(Myboard, ShowBoard, ROWS, COLS);			//����
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));		//��ʼ������
	do
	{
		menu();		//��ӡ�˵�

		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("ɨ����Ϸ��ʼ:\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������,����������\n");
			break;
		}
	} while (input);
	return 0;
}