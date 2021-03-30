#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stu    //********************�ṹ��Student
{
	char name[10];
	int age;
};
//**************�����Ƚ�
int cmp_int(const void* x, const void* y)
{
	return *(int*)x - *(int*)y;
}
//**************�������Ƚ�
int cmp_float(const void* x, const void* y)
{
	return (int)(*(float*)x - *(float*)y);
}
//*************�ṹ������Ƚ�
int cmp_age(const void* x, const void* y)
{
	return ((struct Stu*)x)->age - ((struct Stu*)y)->age;
}
//***************�ṹ�����ֱȽ�
int cmp_name(const void* x, const void* y)
{
	return strcmp(((struct Stu*)x)->name,((struct Stu*)y)->name);

}
//***********��������
void test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	printf("��������:\n");
	for (; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//**************����������
void test2()
{
	float arr[] = { 9.3,4.5,6.7,7.8,4.9,2.81,6.6, };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_float);
	int i = 0;
	printf("����������:\n");
	for (; i < sz; i++)
	{
		printf("%f ", arr[i]);
	}
	printf("\n");
}

//***************���ṹ����������
void test3()
{
	struct Stu s[3] = { {"zhangsan",35},{"lisi",30},{"wangwu",22} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_age);
}

//****************���ṹ����������
void test4()
{
	struct Stu s[3] = { {"zhangsan",35},{"lisi",30},{"wangwu",22} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_name);
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}