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
	for (int i = 1; i <= row  ; i++)			//��ӡ������
		printf("%d ", i);
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);			//��ӡ������
		for (int j = 1; j <= col; j++)
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
int Num(char board[ROWS][COLS],int x,int y)			//ͳ�Ƶ�ǰλ����Χ�м�����
{
	return board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] +
		board[x][y - 1] + board[x][y + 1] +
		board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] - 8 * '0';		
}
int Blank(char board[ROWS][COLS], char ShowBoard[ROWS][COLS], int x, int y)		//�жϵ�ǰλ����Χ�ǲ���û����
{
	 int count = 0;		//չ���ĸ�����
	for (int i = x - 1; i <= x + 1 && i >=0 && i <= ROW+1; i++)
	{
		for (int j = y - 1; j <= y + 1 && j >=0 && j <=COL; j++)
		{
			if (i == x && j == y)		//��������Ϊ��x��y����λ��
				;
			else if (ShowBoard[i][j] == '*' && board[i][j] != '1')		//�������(i,j)��û�б���ʼ�����Ҳ�Ϊ�ף��ж�����Χ��û����
			{															//�����ΧҲû���ף�����չ��	
				int cnt = Num(board, i, j);                                                                               
				if (cnt == 0)
				{
					ShowBoard[i][j] = ' ';
					count += Blank(board, ShowBoard, i, j);				//�����ж����������Χ��λ���Ƿ���Ҫչ��
				}
				else ShowBoard[i][j] = cnt + '0';
				if (i >= 1 && i <= ROW && j >= 1 && j <= COL)		//��չ���ĸ�������Ч���̷�Χ��ʱ��count++
					count++;
			}
		}
	}
	return count;		//�ܹ�չ���˶��ٸ�����
}
void FindBoard(char board[ROWS][COLS],char ShowBoard[ROWS][COLS],int row, int col)			//����
{
	int cnt = ROW * COL - COUNT;
	int time = 1;		//timeΪ1ʱ��ʾ�ǵ�һ��
	int over = 0;
	//PrintBoard(board, row, col);
	while (1)		
	{
		printf("��ѡ��-> \n1������   2�����\n");
		int choose = 0;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			while (1)		//����ѭ��
			{
				printf("���������׵�����\n");
				int x = 0;
				int y = 0;
				scanf("%d%d", &x, &y);
				if (x < 1 || x >row || y < 1 || y > col)
				{
					printf("����Ƿ�������������\n");
				}
				else
				{
					if (board[x][y] == '1')
					{
						if (time) //�����һ�ξ�������,����������׵�λ��
						{
							board[x][y] = '0';
							while (1)		//���õ�һ���׵�λ��
							{
								int x1 = rand() % row + 1;
								int y1 = rand() % col + 1;
								if (board[x1][y1] == '0')
								{
									board[x1][y1] = '1';
									break;		//�������õ�һ���׵�ѭ��
								}
							}
							time = 0;	//time��Ϊ0��ʾ���ǵ�һ��
							if (0 == Num(board, x, y))
							{
								ShowBoard[x][y] = ' ';
							}
							else ShowBoard[x][y] = Num(board, x, y) + '0';
							cnt--;
							int count = Blank(board, ShowBoard, x, y);
							cnt -= count;
							PrintBoard(ShowBoard, row, col);
							goto end;		//��һ���ŵ��ף��ж��Ƿ�����
						}
						else		//���ǵ�һ��
						{
							over = 1;
							break;	//��������ѭ��
						}
					}
					else if (board[x][y] == '0')
					{
						time = 0;
						if (0 == Num(board, x, y))
						{
							ShowBoard[x][y] = ' ';
						}
						else ShowBoard[x][y] = Num(board, x, y) + '0';
						cnt--;
						int count = Blank(board, ShowBoard, x, y);
 						cnt -= count;
						PrintBoard(ShowBoard, row, col);
						break;		//��������ѭ��
					}
				}
			}
			break;		//����switch
		case 2:
			printf("�������ǵ�����\n");
			while (1)	//���ѭ��
			{
				int x1 = 0;
				int y1 = 0;
				scanf("%d%d", &x1, &y1);
				if (x1< 1 || x1>row || y1<1 || y1>col)
					printf("����Խ�磬����������\n");
				else if (ShowBoard[x1][y1] != '*')
					printf("�˴��������Ų��,����������\n");
				else if (ShowBoard[x1][y1] == '*')
				{
					ShowBoard[x1][y1] = '#';
					PrintBoard(ShowBoard, row, col);
					break;		//�������ѭ��
				}
			}
			break;		//����switch
		default:
			printf("�����������������\n");
			break;	//����switch
		}
		end :
		if (over)
		{
			printf("��ʧ���ˣ���Ϸ����\n");
			PrintBoard(board, row, col);
			break;		//��Ϸ����
		}
		if (cnt == 0)
		{
			printf("��ϲ�㣬�ɹ�����\n");
			PrintBoard(board, row, col);
			break;		//��Ϸ����
		}
	}
}