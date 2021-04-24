#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void Exchange(int A[], int B[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		int tmp = A[i];
		A[i] = B[i];
		B[i] = tmp;
	}
}
int main()
{
	int A[10] = { 1, 3, 5, 7, 9, 11, 13, 15,17, 19 };
	int B[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
	int sz = sizeof(A) / sizeof(A[0]);
	int i = 0;
	Exchange(A, B, sz);
	printf("交换后 A = ");
	for (i = 0; i < sz; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n交换后 B = ");
	for (i = 0; i < sz; i++)
	{
		printf("%d ", B[i]);
	}
	return 0;
}
////数组初始化
//void Init(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//		arr[i] = 0;
//}
//
////打印数组
//void Print(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//}
//
////数组输入
//void Get(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//}
////数组反转
//void Reverse(int arr[], int sz)
//{
//	int left = 0; 
//	int right = sz - 1;
//	while (right >= left)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Init(arr, sz);
//	printf("初始化后:\n");
//	Print(arr, sz);
//	printf("输入:\n");
//	Get(arr, sz);
//	printf("数组反转后:\n");
//	Reverse(arr, sz);
//	Print(arr, sz);
//	return 0;
//}
//void BubbleSort(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int cnt = 0;
//		for (j = 0; j < sz -1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				cnt = 1;
//			}
//		}
//		if (!cnt) break;
//	}
//}
//int main()
//{
//	int arr[] = { 8, 9, 3, 4, 6, 7, 1, 21, 13,15 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	BubbleSort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//
//}