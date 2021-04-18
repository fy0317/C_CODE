#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void Move_(char From, char Dest)					//�ƶ�һ��Բ�̣���Բ�̴���Դ�ƶ���Ŀ�ĵ�  ��From �ƶ���Dest 
{
	printf("��һ��Բ�̴�%c���� -> %c����\n", From, Dest);
}
void Hanoi( char A,char B,char C,int  n)	//�ܹ���n��Բ�̣�����n��Բ��  ���� B ���� �� A �����ƶ���  C ����
{
	if (n == 1)								//��ֻ��һ��Բ��ʱ��ֱ��Բ�̴� A �� �ƶ��� C ��
	{
		Move_(A, C);
	}
	else  
	{
		Hanoi(A,C,B,n - 1);				 //����ֵһ��Բ��ʱ�������Ƚ����� ��n -1����Բ�� ���� C����  �� A �����ƶ��� B ����

		Move_(A, C);					//A��ʣ��һ��Բ�̣���ʣ�µ�һ��Բ�̴� A �ƶ��� C
		Hanoi(B, A, C, n - 1);			//�ٽ���n-1����Բ�� ���� A���� �� B���� �ƶ��� C����
	}
}
int main()
{
	
	int  n = 0;							//��ŵ������
	char A = 'A';						//A����
	char B = 'B';						//B����
	char C = 'C';						//C����
	scanf("%d", &n);

	Hanoi(A,B,C,n);						//��n��Բ�̣�������B���ӣ���A�����ƶ���C����
	return 0;
}