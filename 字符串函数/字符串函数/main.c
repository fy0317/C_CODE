#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
struct s   //����һ���ṹ�壬��Ա�����ֺ�����
{
	char name[20];
	int age;
};
void* my_memcpy(void* dest,const void* scr, int sz)//��������
{
	void* ret = dest;
	assert(dest);
	assert(scr);
	if (dest < scr)   //Ŀ�ĵصĵ�ַС��Դ�ĵ�ַ
	{
		//��ǰ��󿽱�
		while (sz--)
		{
			*(char*)dest = *(char*)scr;
			++(char*)dest, ++(char*)scr;
		}
		return ret;
	}
	else
	{
		//�Ӻ���ǰ����
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
		С�˻�����arr1���ڴ���Ϊ:01 00 00 00    02 00 00 00   03 00 00 00    04 00 00 00   05 00 00 00  06 00 00 00  07 00 00 00  08 00 00 00
																			   09 00 00 00   0a 00 00 00
		��arr1+2 ����5��Ԫ�ص� arr1+4�У��Ӻ���ǰ�������Ƚ�07 00 00 00 ��������00��������09 00 00 00 �������00�У�Ȼ�����δӺ���ǰ����
		���ҵ�00��7��������00���ĵ�ַ��00(9�������00�ĵ�ַ)

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
	struct s arr3[] = { {"����",10},{"����",20} };
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