#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
//{
//	int i = 0;
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		if (arr[i] % 2 == 0)
//		{
//			for (int j = i; j < sz; j++)
//			{
//				if (arr[j] % 2)
//				{
//					int tmp = arr[i];
//					arr[i] = arr[j];
//					arr[j] = tmp;
//					break;
//				}
//			}
//		}
//	}
//	//for (int left = 0, right = sz - 1; left < right;)
//	//{
//	//	if (arr[left] % 2 == 0 && arr[right] % 2)
//	//	{
//	//		int tmp = arr[left];
//	//		arr[left] = arr[right];
//	//		arr[right] = tmp;
//	//	}
//	//	if (arr[left] % 2)
//	//		left++;
//	//	if (arr[right] % 2 == 0)
//	//		right--;
//	//}
//	for (int i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}
#include<assert.h>
int my_strlen(const char* arr)
{
	assert(arr);
	int len = 0;
	while (*arr++ != '\0')
	{
		len++;
	}
	return len;
}
int main()
{
	char arr[] = "Hello World";
	int len = my_strlen(arr);
	printf("%d",len);
	return 0;
}
