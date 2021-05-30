#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Person
{
	char name[20];
	int age;
}Person;
int sort_int(void* p1, void* p2)
{
	return *((int*)p1) - *((int*)p2);
}
int sort_name(void* p1, void* p2)
{
	return strcmp(((Person*)p1)->name, ((Person*)p2)->name);
}
void my_qsort(void* Base, unsigned num, unsigned n, int (*cmp)(void*, void*))
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			void* p1 = (char*)Base + j * n;
			void* p2 = (char*)Base + (j + 1) * n;
			int ret = cmp(p1, p2);
			if (ret > 0)
			{
				void* tmp = malloc(n);
				if (tmp == NULL)
					return;
				memcpy(tmp, p1, n);
				memcpy(p1, p2, n);
				memcpy(p2, tmp, n);
				free(tmp);
			}
		}
	}
}
void test_int()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	my_qsort(arr, 10, sizeof(arr[0]), sort_int);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
}

void test_Person()
{
	Person arr[] = 
	{
		{"张三", 20},
		{"李四",18},
		{"王五", 20},
		{"aaa",21}
	};
	my_qsort(arr, 4, sizeof(Person), sort_name);

}
void test()
{
//	int arr[] = { 1,2,3,4 };
////	printf("%d\n", sizeof(arr));
////	printf("%d\n", sizeof(arr+0));
////	printf("%d\n", sizeof(&arr));
////	printf("%d\n", sizeof(*&arr));
////	printf("%d\n", sizeof(arr));
//	char arr = 'a';
//	printf("%d", strlen(arr));
	int calendar[12][31] = { 0 };
	int(*monthpf)[31] = calendar;
	int month = 0, day = 0;
	int cnt = 1;
	for (monthpf = calendar; monthpf < &calendar[12]; monthpf++)
	{
		cnt = 1;
		for (int* dayp = *monthpf; dayp < *monthpf + 31; dayp++)
			*dayp = cnt++;
	}
	for (month = 0; month < 12; month++)
	{
		for (day = 0; day < 31; day++)
			printf("%d ", calendar[month][day]);
		printf("\n");
	}

}
#define N 50
char buffer[N];
char* bufptr = buffer;
void flushbufer()
{
	bufptr = buffer;
}
void bufwriter(char* p, int n)
{
	while (n > 0)
	{
		int k, rem;
		if (bufptr == &buffer[N])
			flushbuffer();
		rem = N - (bufptr - buffer);
		k = n > rem ? rem : n;
		memcpy(bufptr, p, k);
		bufptr += k;
		n -= k;
		p += k;
	}
}
int main()
{
	//test_int();
	//test_Person();
	test();
	return 0;
}

