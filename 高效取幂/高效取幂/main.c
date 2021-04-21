#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Pow(int x, int n)
{
	if (!n) return 1;
	if (n % 2) return x * Pow(x, n - 1);
	else return  Pow(x * x, n / 2);
}
int main()
{
	int x = 0;
	int n = 0;
	scanf("%d%d", &x, &n);
	int ret = Pow(x, n);
	printf("x^n=%d\n", ret);
	return 0;
}