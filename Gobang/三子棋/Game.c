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
			printf("玩家赢!\n");
			break;
		}
		else if (win == '#')
		{
			printf("电脑赢\n");
			break;
		}
		else if (win == '!')
		{
			printf("平局！\n");
			break;
		}
		ComputerMove(arr, row, lin);
		ShowBoard(arr, row, lin);
		win = Iswin(arr, row, lin);
		if (win == '*')
		{
			printf("玩家赢!\n");
			break;
		}
		else if (win == '#')
		{
			printf("电脑赢\n");
			break;
		}
		else if (win == '!')
		{
			printf("平局！\n");
			break;
		}

	}

}
//***********玩家下棋
void Playermove(char arr[Row][Lin], int row, int lin)
{
	int i, j;
	printf("玩家下棋->请输入坐标\n");
	scanf("%d%d", &i, &j);
	if (arr[i - 1][j - 1] == ' ')  //当前位置是否已经被占据
	{
		arr[i - 1][j - 1] = '*';
	}
	else if (i > row || j > lin)  
	{
		printf("超出棋盘范围，请重新输入\n");
		scanf("%d%d", &i, &j);
	}
	else
	{
		printf("该位置已经有棋子，请重新输入坐标");
		scanf("%d%d", &i, &j);
	}
}
//*******电脑下棋
void ComputerMove(char arr[Row][Lin], int row, int lin)
{
	int x = 0, y = 0;
	printf("电脑下棋:\n");

	while (1)
	{
		x = rand() % row;		//保证行从0到row-1
		y = rand() % lin;	   //保证列从0到lin-1
		if (arr[x][y] == ' ')   //判断当前位置是否被占
		{
			arr[x][y] = '#';
			break;
		}
	}
}

//*********三子棋

//char Iswin(char arr[Row][Lin], int row, int lin)
//{
//	int i, j;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < lin; j++)
//		{
//			//判断行是否相等
//			if (j + 2 < lin)
//			{
//				if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] == arr[i][j + 2]) && (arr[i][j] != ' '))
//				{
//					printf("行相等\n");
//					return arr[i][j];
//				}
//			}
//			//判断列是否相等
//			if (j + 2 < row)
//			{
//				if (arr[j][i] == arr[j + 1][i] && arr[j][i] == arr[j + 2][i] && arr[j][i] != ' ')
//				{
//					printf("列相等\n");
//					return arr[j][i];
//				}
//			}
//			//判断斜对角线是否相等
//			if (i + 2 <row&&j-2>0)
//			{
//				if (arr[i][j] == arr[i + 1][j - 1] && arr[i][j] == arr[i + 2][j - 2]&&arr[i][j]!=' ')
//				{
//					printf("斜对角线相等\n");
//					return arr[i][j];
//				}
//			}
//			
//		}
//		//判断主对角线是否相等
//		if (i + 2 < row&&i+2<lin)
//		{
//			if (arr[i][i] == arr[i + 1][i + 1] && arr[i][i] == arr[i + 2][i + 2]&&arr[i][i]!=' ')
//			{
//				printf("主对角线相等\n");
//				return arr[i][i];
//			}
//		}
//	}
//	//判断棋盘是否全部填完
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
//五子棋
char Iswin(char arr[Row][Lin], int row, int lin)
{
	int i, j,cnt1,cnt2;
	for (i = 0; i < row; i++)
	{
		cnt1 = 0;
		cnt2 = 0;
		//判断行是否相等
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
		//判断列是否相等
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
	//判断主对角线是否相等
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
	//判断斜对角线
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
	//判断棋盘是否全部填完
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