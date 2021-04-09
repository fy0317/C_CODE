#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n = 0, m = 0, b = 0, i = 0, j = 0;
	int arr[100003] = { 0 };
	scanf("%d%d", &m, &n);
	b = n * m;
	if (n == 0) printf("0");
	else {
		while (n >= 0)
		{
			arr[i] = b % 10;
			b = (n - 1) * m + b / 10;
			n--, i++;
		}
	}
	if (arr[i - 1] == 0)
		j = i - 2;
	else j = i - 1; 
	for (; j >= 0; j--)
	{

		printf("%d", arr[j]);
	}
	return 0;
}