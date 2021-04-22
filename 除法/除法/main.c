#include<stdio.h>

int devid(int a, int b, int* result);
int main()
{
	int a, b,result;
	scanf_s("%d%d", &a, &b);
	if (devid(a, b, &result))
	{
		printf("%d/%d=%d", a, b, result);
	}
	else
	{
		printf("Ê§°Ü\n");
	}
	return 0;
}

int devid(int a, int b, int* result)
{
	int ret = 1;
	if (b != 0)
		*result = a / b;
	else ret = 0;
	return ret;
}