#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void Move_(char From, char Dest)					//移动一个圆盘，将圆盘从来源移动到目的地  从From 移动到Dest 
{
	printf("将一个圆盘从%c柱子 -> %c柱子\n", From, Dest);
}
void Hanoi( char A,char B,char C,int  n)	//总共有n个圆盘，将这n个圆盘  借助 B 柱子 从 A 柱子移动到  C 柱子
{
	if (n == 1)								//当只有一个圆盘时，直接圆盘从 A 柱 移动到 C 柱
	{
		Move_(A, C);
	}
	else  
	{
		Hanoi(A,C,B,n - 1);				 //当不值一个圆盘时，我们先将上面 （n -1）个圆盘 借助 C柱子  从 A 柱子移动到 B 柱子

		Move_(A, C);					//A柱剩余一个圆盘，将剩下的一个圆盘从 A 移动到 C
		Hanoi(B, A, C, n - 1);			//再将（n-1）个圆盘 借助 A柱子 从 B柱子 移动到 C柱子
	}
}
int main()
{
	
	int  n = 0;							//汉诺塔层数
	char A = 'A';						//A柱子
	char B = 'B';						//B柱子
	char C = 'C';						//C柱子
	scanf("%d", &n);

	Hanoi(A,B,C,n);						//将n个圆盘，借助于B柱子，从A柱子移动到C柱子
	return 0;
}