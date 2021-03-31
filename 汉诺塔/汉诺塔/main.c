#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void move(char a, char b, char c, int n)
{
	if (n == 1)
		printf("%c→%c\n", a, c);   //直接将木块从a移动到c
	else
	{
		move(a, c, b, n - 1);//将n-1个木块借助c,从a移动到b
		printf("%c→%c\n", a, c);   //a上剩余一块，直接移动到c

		move(b, a, c, n - 1);//将b上n-1个木块借助a，从b移动到c
	}
}
int main()
{
	int n;          //汉诺塔多少层
	scanf_s("%d", &n);
	move('A', 'B', 'C', n);  //函数move，将n方块个从借助B，从A移动到C
	return n;
	
}