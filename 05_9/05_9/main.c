#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	for (int i = 0; i <= 100000; i++)
	{
		int n = 0;
		int tmp = i;
		int sum = 0;
		while (tmp)
		{
			tmp /= 10;
			n++;
		}
		tmp = i;
		while (tmp)
		{
			sum += pow(tmp % 10, n);
			tmp /= 10;
		}
		if (sum == i)
			printf("%d ", i);
	}
	return 0;
}
//int main()
//{
//	int arr[] = { 1,2,3,4,78,2,5,8,9 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}
//int main()
//{
//	int x = 0;
//	int n = 0;
//	int sum = 0;
//	scanf("%d%d", &x, &n);
//	int tmp = x;
//	for (int i = 0; i < n; i++)
//	{
//		sum += x;
//		x = 10 * x + tmp;
//	}
//	printf("sum = %d", sum);
//	return 0;
//}
