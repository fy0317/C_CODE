/*********************************
* 
* 
* 
	��һ�����������в���һ����
	����Ϊ��

**********************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10 };
//	int n = 0;
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	int mid = (left + right) / 2;
//	scanf("%d", &n);
//	while (left<=right)
//	{
//		if (arr[mid] < n)
//			left = mid + 1;
//		else if (arr[mid] > n)
//			right = mid - 1;
//		else {
//			printf("�ҵ��ˣ��±���:%d\n", mid);
//			break;
//		}
//		mid = (left + right) / 2;
//	}
//	if (left > right)
//		printf("û�ҵ�\n");
//	return 0;
//}

#include <string.h>
#include <windows.h>

int main()
{
	char arr1[] = "welcome to bit!!!!!!";
	char arr2[] = "####################";
	int left = 0;
	int right = strlen(arr1) - 1;

	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000); //˯��1��
		system("cls");//�����Ļ   
		left++;
		right--;
	}
	printf("%s\n", arr2);

	return 0;
}