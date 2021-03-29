#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//ц╟ещеепР
void Bubble(int arr[], int sz)
{
	int i, j;
	for (i = 0; i < sz; i++)
	{
		for (j = 0; j < sz-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int tmp =arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble(arr, sz);
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}