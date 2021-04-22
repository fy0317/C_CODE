#include<stdio.h>
void swap(int* p,int *q);
int main()
{
	int a, b;
	scanf_s("%d%d", &a, &b);
	swap(&a, &b);
	printf("a=%d,b=%d", a, b);
}

void swap(int* p, int* q)
{
	int t;
	t = *p;
	*p = *q;
	*q = t;
}