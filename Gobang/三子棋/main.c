#define _CRT_SECURE_NO_WARNINGS
#include"ShowBoard.h"
#include"Initial.h"
#include"Play.h"
int main()

{
	char arr[Row][Lin] = { 0 };  
	InitialBoard(arr, Row, Lin);//��ʼ������
	int n;
	//�����û�ѡ���Ƿ�ʼ��Ϸ
	printf("**********************************************\n");
	printf("********��ѡ��->   1:��ʼ��Ϸ  2��������Ϸ\n");
	printf("**********************************************\n");
	scanf("%d", &n);
	srand((unsigned int)time(NULL));
	while (1)
	{
		if (n == 1)   //�������1����ʼ��Ϸ
		{
			begin :
			printf("��Ϸ��ʼ->\n");
			ShowBoard(arr, Row, Lin);  //��ʾ����
			Play(arr, Row, Lin);   //��Ϸ����
			break;
		}
		else if (n == 2)
		{
			printf("ȷ��Ҫ������Ϸô��1->ȷ���˳�   2->������Ϸ\n");
			int m;
		again:
			scanf("%d", &m);
			if (m == 1)
				break;
			else if (m == 2)
				goto begin;
			else
			{
				printf("�����������������\n");
				goto again;
			}
		}
		else 
		{
			printf("ѡ���������������");
			scanf("%d", &n);
		}
	}
	srand((unsigned)time(NULL));
	return 0;
}
