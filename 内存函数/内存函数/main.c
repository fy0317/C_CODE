#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void* my_memcpy(void* dest, const void* src, int num)
{
	char* p1 = (char*)dest;
	const char* p2 = (char*)src;
	while (num--)
	{
		*p1++ = *p2++;
	}
	return dest;
}
void test1()
{
	int arr1[] = { 1, 2, 3,4, 5,6,7,8,9,10 };
	int arr2[10];
	my_memcpy(arr2, arr1, 20);
}
int main()
{
	//char c = '2';
	//printf("%d\n",isdigit(c));
	//char arr[10];
	//for (int i = 0; i < 10; i++)
	//{
	//	scanf("%c", &arr[i]);
	//	if (islower(arr[i]))
	//		arr[i] = toupper(arr[i]);
	//	printf("%c ", arr[i]);
	//}
	test1();
	return 0;
}

