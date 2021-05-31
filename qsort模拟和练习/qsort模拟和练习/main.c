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
int cmp_int(const void* p1, const void* p2);		//�Ƚ�����
int cmp_float(const void* p1, const void* p2);		//�Ƚϸ�����
int cmp_Person_Byname(const void* p1, const void* p2);		//�������ֱȽ�
int cmp_Person_Byage(const void* p1, const void* p2);		//��������Ƚ�
void PrintPersonArr(const Person* pArr, int n);				//��ӡPerson
void PrintIntArr(const int* int_arr,int sz);				//��ӡ��������
void PrintFloatArr(const int* float_arr,int sz);			//��ӡ����������


void test1()
{
	int int_arr[] = { 10, 9, 8, 7,6,5,4,3,2,1 };
	float float_arr[] = { 4.7,6.8,9.9,2.0,4.5,11.4, 7.8 };

	//������������
	int sz = sizeof(int_arr) / sizeof(int);
	qsort(int_arr, sz, sizeof(int), cmp_int);
	PrintIntArr(int_arr, sz);

	//���򸡵�������
	sz = sizeof(float_arr) / sizeof(float);
	qsort(float_arr, sz, sizeof(float), cmp_float);
	PrintFloatArr(float_arr, sz);

	//����Person������
	Person person_arr[] = {
		{"����", 20},
		{"����", 29},
		{"����", 18},
		{"С��", 30}
	};
	sz = sizeof(person_arr) / sizeof(Person);
	//������������
	printf("������������:\n");
	qsort(person_arr, sz, sizeof(Person), cmp_Person_Byname);
	PrintPersonArr(person_arr, sz);
	//������������
	printf("������������:\n");
	my_qsort(person_arr, sz, sizeof(Person), cmp_Person_Byage);
	PrintPersonArr(person_arr, sz);
}
int main()
{
	test1();
	return 0;
}

int cmp_int(const void* p1, const void* p2)		//�Ƚ�����
{
	return (*(int*)p1) - (*(int*)p2);
}

int cmp_float(const void* p1, const void* p2)		//�Ƚϸ�����
{
	float ret = (*(float*)p1) - (*(float*)p2);
	if (ret > 1e-7)
		return 1;
	else if (ret < -1e-7)
		return -1;
	else return 0;
}

int cmp_Person_Byname(const void* p1, const void* p2)		//�������ֱȽ�
{
	return strcmp(((Person*)p1)->name, ((Person*)p2)->name);
}
int cmp_Person_Byage(const void* p1, const void* p2)		//��������Ƚ�
{
	return ((Person*)p1)->age - ((Person*)p2)->age;
}

void PrintPersonArr(const Person* pArr, int n)			//��ӡPerson
{
	if (pArr == NULL)
		return;
	for (int i = 0; i < n; i++)
	{
		printf("������%s,  ���䣺%d\n", pArr[i].name, pArr[i].age);
	}
}

void PrintIntArr(const int* int_arr, int sz)				//��ӡ��������
{
	for (int i = 0; i < sz; i++)
		printf("%d ", int_arr[i]);
	printf("\n");
}
void PrintFloatArr(const float* float_arr, int sz)			//��ӡ����������
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

