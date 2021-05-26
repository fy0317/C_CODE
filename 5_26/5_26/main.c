#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#define COL 5
bool findnum(int arr[][COL], int row, int col, int num)
{
	int i = 0;
	int j = col - 1;
	while (i < row && j >=0 )
	{
		if (num > arr[i][j])
			i++;
		else if (num < arr[i][j])
			j--;
		else return true;
	}
	return false;
}
int main()
{
	int arr[][COL] = {
		{1,2,3,4,5},
		{2,3,4,5,6},
		{6,7,8,9,10},
		{7,8,9,10,11}
	};
	int num;
	scanf("%d", &num);	//目标数字
	int row = sizeof(arr) / COL;
	int ret = findnum(arr, row, COL, num);
	if (ret == false)
		printf("没找到\n");
	else printf("找到了\n");
	return 0;
}
