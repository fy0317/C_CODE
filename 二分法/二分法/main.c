#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int Find_key(int arr[], int key, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
			left = mid + 1;
		else return mid;
	}
	return -1;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,11,12,22,33,44,55,66,67,77,88 };
	int key = 0;
	scanf("%d", &key);
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = Find_key(arr, key, sz);
	if (ret == -1)
		printf("没找到\n");
	else printf("找到了，下标是%d\n", ret);
	return 0;
}