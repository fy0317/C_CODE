#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 101

int f1(const int* arr, int size)
{
	int x1 = 0;
	int i = 0;
	for (i = 1; i < MAX; i++)
	{
		x1 ^= i;
	}
	for (i = 0; i < size; i++)
	{
		x1 ^= arr[i];
	}
	return x1;
}
int f2(int* arr, int size)
{
	int tmp[MAX] = { 0 };
	int i;
	for (i = 0; i < size; i++)
	{
		tmp[arr[i]]++;
	}
	for (i = 1; i < size; i++)
		if (tmp[i] == 2)
			return i;
}
void test1()
{
	int arr[MAX] = { 0 };
	int i;
	for (i = 0; i < MAX - 1; i++)
	{
		arr[i] = i + 1;
	}
	arr[i] = rand() % (MAX - 1) + 1;
	int ret = 0;
	//·½·¨1£º
	ret = f1(arr, MAX);
	printf("\n");
	printf("%d\n", ret);
	ret = f2(arr, MAX);
	printf("%d\n", ret);
}
int main()
{
	srand(time(NULL));
	test1();
	return 0;
}

