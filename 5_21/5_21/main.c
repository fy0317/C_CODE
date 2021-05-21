#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	//char a[1000];
	//for (int i = 0; i < 1000; i++)
	//	a[i] = -1 - i;
	//printf("%d",strlen(a));
	int a = 9;
	float* p = (float*)&a;
	printf("%f\n", *p);
	*p = 9.0;
	printf("%d\n", a);
	printf("%f\n", *p);
	return 0;
}
