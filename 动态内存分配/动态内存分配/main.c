#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//错误代码:
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);    //错误1:开辟了一块动态内存，GetMemory函数结束后，没有释放这块空间，而且因为找不到这块空间
//	                           //   造成内存泄漏
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);   //str只是传值，GetMemory结束后，str还是NULL，因此在对NULLstrcpy时，程序会崩溃
//	strcpy(str, "Hello world!");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}


//修改1:

//void Getmemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test()
//{
//	char* str = NULL;
//	Getmemory(&str);
//	strcpy(str, "Hello World!");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//修改2:
//char* GetMemory()
//{
//	char* p = (char*)malloc(100);
//	return p;
//}
//void Test()
//{
//	char* ptr = NULL;
//	ptr = GetMemory();
//	strcpy(ptr, "Hello World!");
//	printf(ptr);
//	free(ptr);
//	ptr = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}


//***********
//
//    柔性数组
//
//***********


//#include<Windows.h>
//struct S
//{
//	int n;
//	int arr[];
//};
//int main()
//{
//	struct S s = { 0 };
//	//printf("%d\n", sizeof(s));
//	struct S* p = malloc(sizeof(struct S) + 5 * sizeof(int));
//	p->n = 100;
//	for (int i = 0; i < 5; i++)
//	{
//		p->arr[i] = i;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", p->arr[i]);
//	}
//	Sleep(1000);
//	struct S* ptr=(struct S*)realloc(p, sizeof(struct S) + sizeof(int) * 10);
//	if (ptr != NULL)
//		p = ptr;
//	for (int i = 0; i < 10; i++)
//	{
//		p->arr[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", p->arr[i]);
//	}
//	free(ptr);
//	ptr = NULL;
//	return 0;
//}


//利用指针实现动态数组

struct S
{
	int n;
	int* arr;
};
int main()
{
	struct S* p = (struct S*)malloc(sizeof(struct S));
	p->arr = (int*)malloc(sizeof(int) * 5);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		p->arr[i] = i;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", p->arr[i]);
	}
	printf("\n");
	int * tmp = (int*)realloc(p->arr, sizeof(int) * 10);
	if (tmp != NULL)
		p->arr = tmp;
	for (i = 0; i < 10; i++)
	{
		p->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p->arr[i]);
	}
	printf("\n");
	free(p->arr);
	p->arr = NULL;
	free(p);
	p = NULL;

	return 0;
}