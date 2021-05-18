#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
/*
将一句话的单词进行倒置，标点不倒置。
比如 I like beijing. 经过函数后变为：beijing. like I
*/
void reverse(char arr[], int left, int right)
{
	while (left < right)
	{
		char tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
int main()
{
	char arr[101] = { 0 };
	gets(arr);
	int len = strlen(arr);
	int left = 0;
	int right = len - 1;
	reverse(arr, left, right);
	for (left = 0; left < len;)
	{
		right = left;
		while (arr[right] != ' ' && arr[right] != 0)
			right++;
		reverse(arr, left, right - 1);
		if (arr[right] == ' ')
			left = right + 1;
		else left = right;
	}
	//for (int i = 0; i < len; i++)
	//{
	//	if (arr[i] == ' ')
	//	{
	//		right = i - 1;
	//		reverse(arr, left, right);
	//		left = right + 2;
	//	}
	//	else if (arr[i + 1] == 0)
	//		reverse(arr, left, len - 1);
	//}
	printf("%s", arr);
	return 0;
}
