#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void* my_memmove(void* dest, const void* src, size_t size)
{
	if (dest == NULL || src == NULL)return NULL;
	void* ret = dest;
	if (src < dest)		//从后往前拷贝
	{
		while (size)
		{
			*((char*)dest + size - 1) = *((char*)src + size - 1);
			size--;
		}
	}
	else               //从前往后拷贝
	{
		while (size--)		
		{
			*(char*)dest = *(char*)src;
			((char*)dest)++;
			((char*)src)++;
		}
	}
	return ret;
}

void* my_memcpy(void* dest, const void* src, size_t size)
{
	if (dest == NULL || src == NULL)return NULL;
	void* ret = dest;
	while (size--)
	{
		*(char*)dest = *(char*)src;
		((char*)dest)++;
		((char*)src)++;
	}
	return ret;
}
void test1()
{
	int arr[20] = { 0 };
	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
	my_memcpy(arr, arr1, sizeof(arr1));
	//my_memmove(arr + 4, arr + 2, sizeof(int) * 4);
	//my_memmove(arr1 + 2, arr1 + 4, sizeof(int) * 4);
}
int main()
{
	test1();
	return 0;
}

