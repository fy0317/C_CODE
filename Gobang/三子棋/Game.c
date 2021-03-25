#define _CRT_SECURE_NO_WARNINGS
#include"ShowBoard.h"
void Play(char arr[Row][Lin], int row, int lin)
{
	char win = ' ';
	while (win == ' ')
	{
		Playermove(arr, row, lin);
		ShowBoard(arr, row, lin);
		win=Iswin(arr, row, lin);
		if (win == '*')
		{
			printf("���Ӯ!\n");
			break;
		}
		else if (win == '#')
		{
			printf("����Ӯ\n");
			break;
		}
		else if (win == '!')
		{
			printf("ƽ�֣�\n");
			break;
		}
		ComputerMove(arr, row, lin);
		ShowBoard(arr, row, lin);
		win = Iswin(arr, row, lin);
		if (win == '*')
		{
			printf("���Ӯ!\n");
			break;
		}
		else if (win == '#')
		{
			printf("����Ӯ\n");
			break;
		}
		else if (win == '!')
		{
			printf("ƽ�֣�\n");
			break;
		}

	}

}
//***********�������
void Playermove(char arr[Row][Lin], int row, int lin)
{
	int i, j;
	printf("�������->����������\n");
	scanf("%d%d", &i, &j);
	if (arr[i - 1][j - 1] == ' ')  //��ǰλ���Ƿ��Ѿ���ռ��
	{
		arr[i - 1][j - 1] = '*';
	}
	else if (i > row || j > lin)  
	{
		printf("�������̷�Χ������������\n");
		scanf("%d%d", &i, &j);
	}
	else
	{
		printf("��λ���Ѿ������ӣ���������������");
		scanf("%d%d", &i, &j);
	}
}
//*******��������
void ComputerMove(char arr[Row][Lin], int row, int lin)
{
	int x = 0, y = 0;
	printf("��������:\n");

	while (1)
	{
		x = rand() % row;		//��֤�д�0��row-1
		y = rand() % lin;	   //��֤�д�0��lin-1
		if (arr[x][y] == ' ')   //�жϵ�ǰλ���Ƿ�ռ
		{
			arr[x][y] = '#';
			break;
		}
	}
}

//*********������

//char Iswin(char arr[Row][Lin], int row, int lin)
//{
//	int i, j;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < lin; j++)
//		{
//			//�ж����Ƿ����
//			if (j + 2 < lin)
//			{
//				if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i][j + 2]) && (arr[i][j] != ' '))
//				{
//					printf("�����\n");
//					return arr[i][j];
//				}
//			}
//			//�ж����Ƿ����
//			if (j + 2 < row)
//			{
//				if (arr[j][i] == arr[j + 1][i] && arr[j][i] == arr[j + 2][i] && arr[j][i] != ' ')
//				{
//					printf("�����\n");
//					return arr[j][i];
//				}
//			}
//			//�ж�б�Խ����Ƿ����
//			if (i + 2 <row&&j-2>0)
//			{
//				if (arr[i][j] == arr[i + 1][j - 1] && arr[i][j] == arr[i + 2][j - 2]&&arr[i][j]!=' ')
//				{
//					printf("б�Խ������\n");
//					return arr[i][j];
//				}
//			}
//			
//		}
//		//�ж����Խ����Ƿ����
//		if (i + 2 < row&&i+2<lin)
//		{
//			if (arr[i][i] == arr[i + 1][i + 1] && arr[i][i] == arr[i + 2][i + 2]&&arr[i][i]!=' ')
//			{
//				printf("���Խ������\n");
//				return arr[i][i];
//			}
//		}
//	}
//	//�ж������Ƿ�ȫ������
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < lin; j++)
//		{
//			if (arr[i][j] == ' ')
//				return ' ';
//		}
//	}
//	return '!';
//}
//������
char Iswin(char arr[Row][Lin], int row, int lin)
{
	int i, j,cnt1,cnt2;
	for (i = 0; i < row; i++)
	{
		cnt1 = 0;
		cnt2 = 0;
		//�ж����Ƿ����
		if (i + 4 < row)
		{
			for (j = 0; j < lin; j++)
			{
				if (arr[i][j] == arr[i][j + 1] && arr[i][j] == '*')
					cnt1++;
				if (arr[i][j] == arr[i][j + 1] && arr[i][j] == '#')
					cnt2++;
				if (arr[i][j] != arr[i][j + 1])
					cnt1 = 0, cnt2 = 0;
				if (cnt1 == 4 || cnt2 == 4)
					return arr[i][j];
			}
		}
		//�ж����Ƿ����
		for (j = 0; j < lin; j++)
		{
			if (arr[j][i] == arr[j+1][i] && arr[j][i] == '*')
				cnt1++;
			if (arr[j][i] == arr[j+1][i] && arr[j][i] == '#')
				cnt2++;
			if (arr[j][i] != arr[j+1][i])
				cnt1 = 0, cnt2 = 0;
			if (cnt1 == 4 || cnt2 == 4)
				return arr[j][i];
		}
	}
	//�ж����Խ����Ƿ����
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lin; j++)
		{
			if (i + 4 < row && j + 4 < lin)
			{
				if (arr[i][j] == arr[i + 1][j + 1] && arr[i][i] == arr[i + 2][j + 2])
					if (arr[i][j] == arr[i + 3][j + 3] && arr[i][j] == arr[i + 4][j + 4] && arr[i][j] != ' ')
						return arr[i][j];
			}
		}

	}
	//�ж�б�Խ���
	for (i =0; i<row; i++)
	{
		for (j =lin-1; j>=0; j--)
		{
			if (i + 4 < row && j - 4 >=0)
			{
				if (arr[i][j] == arr[i + 1][j - 1]&&arr[i][j]!=' ')
					if (arr[i][j] == arr[i + 2][j - 2] && arr[i][j] == arr[i + 3][j - 3] && arr[i][j] == arr[i + 4][j - 4])
					{
						if (arr[i][j] == '*')
							return '*';
						else return  '#';
					}
			}

		}
	}
	//�ж������Ƿ�ȫ������
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lin; j++)
		{
			if (arr[i][j] == ' ')
				return ' ';
		}
	}
	return '!';
}