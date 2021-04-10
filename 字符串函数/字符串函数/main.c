#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
struct s   //定义一个结构体，成员是名字和年龄
{
	char name[20];
	int age;
};
void* my_memcpy(void* dest,const void* scr, int sz)//拷贝函数
{
	void* ret = dest;
	assert(dest);
	assert(scr);
	if (dest < scr)   //目的地的地址小于源的地址
	{
		//从前向后拷贝
		while (sz--)
		{
			*(char*)dest = *(char*)scr;
			++(char*)dest, ++(char*)scr;
		}
		return ret;
	}
	else
	{
		//从后向前拷贝
		//dest = sz-1 + (char*)dest;
		//scr = sz-1 + (char*)scr;
		//while (sz--)
		//{
		//	*(char*)dest = *(char*)scr;
		//	--(char*)dest, --(char*)scr;

		//}

		/*
		*
		* 
		* 
		小端环境，arr1在内存中为:01 00 00 00    02 00 00 00   03 00 00 00    04 00 00 00   05 00 00 00  06 00 00 00  07 00 00 00  08 00 00 00
																			   09 00 00 00   0a 00 00 00
		将arr1+2 拷贝5个元素到 arr1+4中，从后往前拷贝，先将07 00 00 00 最后的两个00，拷贝到09 00 00 00 最后两个00中，然后依次从后往前拷贝
		先找到00（7最后的两个00）的地址和00(9最后两个00的地址)

		*/
		while (sz--)
		{
			*((char*)dest + sz) = *((char*)scr + sz);
		}
		return dest;
	}

}
int main()
{
	struct s arr3[] = { {"张三",10},{"李四",20} };
	struct s arr4[2] = { 0 };
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10};
	int arr2[5] = { 0 };
	my_memcpy(arr1+4, arr1+2,5*sizeof(arr1[0]));
	for (int i = 0; i < 10;i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}