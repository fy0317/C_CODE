#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* arr1[10] = { &arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6],&arr[7],&arr[8],&arr[9]};
//	int(*arr2)[10] = &arr;
//	int i = 0;
//	////用arr输出每个元素
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", arr[i]);
//	//}
//	//printf("\n");
//	////用arr1输出每个元素
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", *(arr1[i]));
//	//}
//	//printf("\n");
//	////用 p 输出每个元素
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", *(*p + i));
//	//}
//	//printf("\n");
//
//	printf("%p\n", arr2+1);			
//
//	printf("%p\n", *arr2+1);		
//
//	printf("%p\n", &arr[1]);		//输出arr[1]的地址
//	
//	return 0;
//
//}

int Add(int x, int y)
{
	return x + y;
}
int  main()
{
	int a = 3;
	int b = 2;
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	int (*p1)(int x, int y);
	int (*p2)(int x, int y);
	sum1 = Add(a, b);
	printf("%d\n", sum1);
	p1 = &Add;
	sum2 = p1(a, b);
	printf("%d\n", sum2);
	p2 = Add;
	sum3 = (*p2)(a,b);
	printf("%d\n", sum3);
	return 0;
}