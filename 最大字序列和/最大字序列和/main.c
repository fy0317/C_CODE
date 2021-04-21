#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//求一个数组中，连续元素相加，和的最大值
int MaxSubSum(const int arr[], int n)  
{
	int i = 0;
	int j = 0;
	int Max = 0;			//最大值
	int sum = 0;			//当前的和	
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = i; j < n; j++)		
		{
			sum += arr[j];
			if (sum > Max)
			{
				Max = sum;
			}
		}
	}
	return Max;
}

//int MaxSubSum1(const int arr[], int Left, int Right)
//{
//	int MaxLeftSum, MaxRightSum;
//	int MaxLeftBorderSum, MaxRightBorderSum;
//	int LeftBorderSum, RightBorderSum;
//	int Center, i;
//	if (Left == Right)
//	{
//		if (arr[Left] > 0)
//			return arr[Left];
//		else return 0;
//	}
//	Center = (Left + Right) / 2;
//	MaxLeftSum = MaxSubSum1(arr, Left, Center);
//	MaxRightSum = MaxSubSum1(arr, Center + 1, Right);
//	MaxLeftBorderSum = 0, LeftBorderSum = 0;
//	for (i = Center; i >= Left; i--)
//	{
//		LeftBorderSum += arr[i];
//		if (LeftBorderSum > MaxLeftBorderSum)
//			MaxLeftBorderSum = LeftBorderSum;
//	}
//	MaxRightBorderSum = 0, RightBorderSum = 0;
//	for (i = Center + 1; i <= Right; i++)
//	{
//		RightBorderSum += arr[i];
//		if (RightBorderSum > MaxRightBorderSum)
//			MaxRightBorderSum = RightBorderSum;
//	}
//	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
//}
//int Max3(int max1, int max2, int max3)
//{
//	int max = max1 > max2 ? max1 : max2;
//	max = max > max3 ? max : max3;
//	return max;
//}

int MaxSubSum2(int arr[], int n)
{
	int i = 0;
	int MaxSum = 0;
	int ThisSum = 0;
	for (i = 0; i < n; i++)
	{
		ThisSum += arr[i];
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)			//如果当前和小于0，则前面的数字舍弃，重新求和
			ThisSum = 0;
	}
	return MaxSum;
}
int main()
{
	int arr[] = { 4,-3,5,-2,-1,2, 6, -2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int max = MaxSubSum(arr, sz);
	printf("%d\n", max);
	//max = MaxSubSum1(arr, 0, 7);
	//printf("%d\n", max);
	max = MaxSubSum2(arr,sz);
	printf("%d\n", max);
	return 0;
}