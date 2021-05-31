#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
void reverse_arr(char* str, int n)
{
	assert(str);
	int len = strlen(str);
	if (n >= len || n == 0)
		return;
	else
	{
		char* arr = malloc(len + 1);
		assert(arr);
		strncpy(arr, str + n,len - n );
		strncpy(arr + len - n, str, n);
		arr[len] = 0;
		strcpy(str, arr);
		free(arr);
	}
}
int is_reverse(char* str, char* find)		//从str中找find
{
	if (!str || !find)
		return -1;
	int len1 = strlen(str);
	int len2 = strlen(find);
	if (len1 != len2)
		return 0;
	char* tmp = malloc(2 * len1 + 1);
	assert(tmp);
	strcpy(tmp, str);
	strcat(tmp, str);
	for (int i = 0; i < len1; i++)
	{
		if (strncmp(find, tmp + i, len1) == 0)
		{
			free(tmp);
			return 1;
		}
	}
	free(tmp);
	return 0;
}
void test1()
{
	char arr[] = "hello world";
	int n = 0;
	printf("翻转前：%s\n", arr);
	scanf("%d", &n);
	reverse_arr(arr, n);
	printf("翻转后：%s\n", arr);
}
void test2()
{
	char arr1[] = "abcd";
	char arr2[] = "ABCD";
	char arr3[] = "AABCD";
	char arr4[] = "BCDAA";
	int ret = is_reverse(arr1, arr2);
	printf("%d\n", ret);
	printf("%d\n", is_reverse(arr3, arr4));
}
int main()
{
	//test1();
	test2();
	return 0;
}
