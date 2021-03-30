#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stu    //********************结构体Student
{
	char name[10];
	int age;
};
//**************整数比较
int cmp_int(const void* x, const void* y)
{
	return *(int*)x - *(int*)y;
}
//**************浮点数比较
int cmp_float(const void* x, const void* y)
{
	return (int)(*(float*)x - *(float*)y);
}
//*************结构体年龄比较
int cmp_age(const void* x, const void* y)
{
	return ((struct Stu*)x)->age - ((struct Stu*)y)->age;
}
//***************结构体名字比较
int cmp_name(const void* x, const void* y)
{
	return strcmp(((struct Stu*)x)->name,((struct Stu*)y)->name);

}
//***********排序整形
void test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	printf("整型排序:\n");
	for (; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//**************浮点型排序
void test2()
{
	float arr[] = { 9.3,4.5,6.7,7.8,4.9,2.81,6.6, };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_float);
	int i = 0;
	printf("浮点型排序:\n");
	for (; i < sz; i++)
	{
		printf("%f ", arr[i]);
	}
	printf("\n");
}

//***************按结构体年龄排序
void test3()
{
	struct Stu s[3] = { {"zhangsan",35},{"lisi",30},{"wangwu",22} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_age);
}

//****************按结构体名字排序
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