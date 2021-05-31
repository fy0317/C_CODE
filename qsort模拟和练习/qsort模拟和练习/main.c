#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Person
{
	char name[20];
	int age;
}Person;
void my_qsort(void* arr, unsigned num, unsigned size, int (*cmp)(const void*,const void*));
int cmp_int(const void* p1, const void* p2);		//比较整型
int cmp_float(const void* p1, const void* p2);		//比较浮点型
int cmp_Person_Byname(const void* p1, const void* p2);		//根据名字比较
int cmp_Person_Byage(const void* p1, const void* p2);		//根据年龄比较
void PrintPersonArr(const Person* pArr, int n);				//打印Person
void PrintIntArr(const int* int_arr,int sz);				//打印整型数组
void PrintFloatArr(const int* float_arr,int sz);			//打印浮点型数组


void test1()
{
	int int_arr[] = { 10, 9, 8, 7,6,5,4,3,2,1 };
	float float_arr[] = { 4.7,6.8,9.9,2.0,4.5,11.4, 7.8 };

	//排序整型数组
	int sz = sizeof(int_arr) / sizeof(int);
	qsort(int_arr, sz, sizeof(int), cmp_int);
	PrintIntArr(int_arr, sz);

	//排序浮点型数组
	sz = sizeof(float_arr) / sizeof(float);
	qsort(float_arr, sz, sizeof(float), cmp_float);
	PrintFloatArr(float_arr, sz);

	//排序Person型数组
	Person person_arr[] = {
		{"张三", 20},
		{"李四", 29},
		{"王五", 18},
		{"小明", 30}
	};
	sz = sizeof(person_arr) / sizeof(Person);
	//根据姓名排序
	printf("根据姓名排序:\n");
	qsort(person_arr, sz, sizeof(Person), cmp_Person_Byname);
	PrintPersonArr(person_arr, sz);
	//根据年龄排序
	printf("根据年龄排序:\n");
	my_qsort(person_arr, sz, sizeof(Person), cmp_Person_Byage);
	PrintPersonArr(person_arr, sz);
}
int main()
{
	test1();
	return 0;
}

int cmp_int(const void* p1, const void* p2)		//比较整型
{
	return (*(int*)p1) - (*(int*)p2);
}

int cmp_float(const void* p1, const void* p2)		//比较浮点型
{
	float ret = (*(float*)p1) - (*(float*)p2);
	if (ret > 1e-7)
		return 1;
	else if (ret < -1e-7)
		return -1;
	else return 0;
}

int cmp_Person_Byname(const void* p1, const void* p2)		//根据名字比较
{
	return strcmp(((Person*)p1)->name, ((Person*)p2)->name);
}
int cmp_Person_Byage(const void* p1, const void* p2)		//根据年龄比较
{
	return ((Person*)p1)->age - ((Person*)p2)->age;
}

void PrintPersonArr(const Person* pArr, int n)			//打印Person
{
	if (pArr == NULL)
		return;
	for (int i = 0; i < n; i++)
	{
		printf("姓名：%s,  年龄：%d\n", pArr[i].name, pArr[i].age);
	}
}

void PrintIntArr(const int* int_arr, int sz)				//打印整型数组
{
	for (int i = 0; i < sz; i++)
		printf("%d ", int_arr[i]);
	printf("\n");
}
void PrintFloatArr(const float* float_arr, int sz)			//打印浮点型数组
{
	for (int i = 0; i < sz; i++)
		printf("%f ", float_arr[i]);
	printf("\n");
}
void my_qsort(void* arr, unsigned num, unsigned size, int (*cmp)(const void*, const void*))
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			char* p1 = (char*)arr + j * size;
			char* p2 = (char*)arr + (j + 1) * size;
			if (cmp(p1, p2) > 0)
			{
				char* tmp = malloc(size);
				memcpy(tmp, p1, size);
				memcpy(p1, p2, size);
				memcpy(p2, tmp, size);
				free(tmp);
			}
		}
	}
}

