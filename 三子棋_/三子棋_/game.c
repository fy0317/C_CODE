#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//��ʼ������
void InitBoard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++);
}
//��ӡ����
void PrintBoard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
			for (j = 0; j < col; j++)
				printf("---");
		printf("\n");
	}
}

//�������
void PlayerMove(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("������壬���������ӵ�����:\n");
	while (1)
	{
		scanf("%d%d", &i, &j);
		if (i <= 0 || j <= 0 || i > ROW || j > COL)
			printf("���������������������\n");
		else
		{
			if (arr[i - 1][j - 1] == 0) 
			{
				arr[i - 1][j - 1] = '*';
				break;
			}
			else printf("�˴��Ѿ���ռ�ã�����������\n");
		}
	}
}
//��������
void CopMove(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("��������:\n");
	while (1)
	{
		i = rand() % row;
		j = rand() % col;
		if (arr[i][j] == 0)
		{
			arr[i][j] = '#';
			break;
		}
	}
}
int IsFull(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			if (arr[i][j] == 0) return 0;
	return 1;
}
char IsWin(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	//�ж�����
	for (i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != 0)
		{
			return  arr[i][1];//
		}
	}

	//�ж�����
	for (i = 0; i < col; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != 0)
		{
			return arr[1][i];
		}
	}

	//�ж϶Խ���
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != 0)
	{
		return arr[1][1];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != 0)
	{
		return arr[1][1];
	}

	//�ж�ƽ��
	//����������˷���1�� ��������0
	int ret = IsFull(arr, row, col);
	if (ret == 1)
	{
		return 'Q';
	}

	//����
	return 'C';
}


