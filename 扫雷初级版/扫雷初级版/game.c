#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void InitBoard(char board[ROWS][COLS], int row, int col, char c)	//��ʼ������
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = c;
	}
}
void PrintBoard(char board[ROWS][COLS], int row, int col)			//��ӡ���� 
{
	printf("  ");
	for (int i = 1; i < row - 1; i++)			//��ӡ������
		printf("%d ", i);
	printf("\n");
	for (int i = 1; i < row - 1; i++)
	{
		printf("%d ", i);			//��ӡ������
		for (int j = 1; j < col - 1; j++)
			printf("%c ", board[i][j]);
		printf("\n");
	}

}
void SetBoard(char board[ROWS][COLS], int row, int col)		//����
{
	for (int cnt = 0; cnt < COUNT;)
	{
		int x = rand() % row + 1;		//���������������
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			cnt++;
		}
	}
}
int Num(char board[ROWS][COLS], int x, int y)			//ͳ�Ƶ�ǰλ����Χ�м�����
{
	return board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] +
		board[x][y - 1] + board[x][y + 1] +
		board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] - 8 * '0';
}
void FindBoard(char board[ROWS][COLS], char ShowBoard[ROWS][COLS], int row, int col)			//����
{
	int x = 0;
	int y = 0;
	int cnt = ROW * COL - COUNT;		//cnt��ʾ���׵���Ŀ�������̴�С��ȥ������
	while (1)
	{
		printf("����������\n");
		scanf("%d%d", &x, &y);
		if (x < 1 || x >row || y < 1 || y > col)
		{
			printf("����Ƿ�������������\n");
		}
		else
		{
			if (board[x][y] == '1')			//��ǰ����λ�����ף���Ϸ����
			{
				printf("��ʧ���ˣ���Ϸ����\n");
				PrintBoard(board, row, col);
				break;
			}
			else if (board[x][y] == '0')		//��ǰ���겻���ף�ͳ����Χ�׵���Ŀ
			{
				if (0 == Num(board, x, y))		//�����Χû���ף�������Ϊ��
				{
					ShowBoard[x][y] = ' ';
				}
				else ShowBoard[x][y] = Num(board, x, y) + '0';  //��Χ���ף�������Ϊ�׵ĸ���
																//����Ϊ���Ǵ�ӡ�����ַ��ͱ��������Ҫ����'0'��������Ӧ�������ַ���
				cnt--;						//ÿ����һ���ף����׵���Ŀ��1
				PrintBoard(ShowBoard, row, col);		//��ӡ��ǰ��ʾ���̵���Ϣ
			}
		}
		if (cnt == 0)		//���з���λ�þ��Ų���
		{
			printf("��ϲ�㣬�ɹ�����\n");
			PrintBoard(board, row, col);
			break;
		}
	}
}