#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void move(char a, char b, char c, int n)
{
	if (n == 1)
		printf("%c��%c\n", a, c);   //ֱ�ӽ�ľ���a�ƶ���c
	else
	{
		move(a, c, b, n - 1);//��n-1��ľ�����c,��a�ƶ���b
		printf("%c��%c\n", a, c);   //a��ʣ��һ�飬ֱ���ƶ���c

		move(b, a, c, n - 1);//��b��n-1��ľ�����a����b�ƶ���c
	}
}
int main()
{
	int n;          //��ŵ�����ٲ�
	scanf_s("%d", &n);
	move('A', 'B', 'C', n);  //����move����n������ӽ���B����A�ƶ���C
	return n;
	
}