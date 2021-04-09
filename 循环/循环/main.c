#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0;
	int j = 0;
	int ret = 1;
	for (i = 100; i <= 200; i++)
	{
		ret = 1;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				ret = 0;
				break;
			}
		}
		if (ret)printf("%d ", i);
	}
}
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if ((year % 4 == 0 && (year % 100) != 0) || (year % 400) == 0)
//			printf("%d ",year);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a=0, b=0;
//	int tmp = 0;
//	scanf("%d %d", &a, &b);
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	while(b!=0)
//	{
//		tmp = a % b;
//		a = b;
//		b = tmp;
//	}
//	printf("%d", a);
//}
//int main()
//{
//	int i = 0;
//	for (i = 3; i <= 100; i+=3)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}
//void Max(int*a, int*b);
//
//int main()
//{
//	int max, mid ,min ;
//	int tmp;
//	scanf("%d %d %d", &max, &mid, &min);
//	Max(&max, &mid);
//	Max(&max, &min);
//	Max(&mid, &min);
//	printf("%d %d %d", max, mid, min);
//	return 0;
//}
//void Max(int* a, int* b)
//{
//	int tmp = 0;
//	if (*a < *b)
//	{
//		tmp = *a;
//		*a = *b;
//		*b = tmp;
//	}
//}