#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#include<stdlib.h>
#include<string.h>
//void mySort(int arr[], int sz)
//{
//	int min = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		min = i;
//		for (int j = i + 1; j < sz; j++)
//		{
//			if (arr[j] < arr[min])
//				min = j;
//		}
//		if (min != i)
//		{
//			int tmp = arr[i];
//			arr[i] = arr[min];
//			arr[min] = tmp;
//		}
//	}
//}
struct Person
{
	char name[40];
	int age;
};
int compare(void* x1, void* x2)
{
	int* p1 = x1;
	int* p2 = x2;
	if (*p1 > *p2) return 1;
	else return 0;
}
int compare1(void* x1, void* x2)
{
	struct Person* p1 = x1;
	struct Person* p2 = x2;
	return strcmp(p1->name, p2->name);
}
void my_qsort(void* arr, int elesize, int len, int (*compare)(void*, void*))		//对任意类型数据进行排序，参数2为元素的大小，参数3位数组长度
{
	for (int i = 0; i < len; i++)
	{
		int min = i;		//假设最小的元素就是i
		char* elepos = (char*)arr + min * elesize;		//找到 min 元素的地址
		for (int j = i + 1; j < len; j++)
		{
			char* cur = (char*)arr + j * elesize;		//找到第j个元素的地址
 			if (compare(elepos, cur) > 0)				//使用回调函数进行比较，返回值大于0则表明 min 不是最小的元素下标
				min = j;
		}
		if (min != i)			//如果min ！=i，说明第i个元素不是最小的元素，交换第i个元素和第min个元素的值，使用memcpy函数
		{
			char* tmp = malloc(elesize);
			char* cur = (char*)arr + min * elesize;
			if (tmp)
			{
				memcpy(tmp, elepos, elesize);
				memcpy(elepos, cur, elesize);
				memcpy(cur, tmp, elesize);
			}
			free(tmp);
			tmp = NULL;
		}
	}
}

int main()
{
	struct Person person[] =
	{
		{"fff",10},
		{"eee",20},
		{"ddd",20},
		{"ccc",20},
		{"bbb",20},
		{"aaa",20},
	};
	int arr[] = { 10,9,8,7,6,5,4 };
	int sz = sizeof(person) / sizeof(person[0]);
	//mySort(arr, sz);
	//for (int i = 0; i < sz; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	my_qsort(person, sizeof(struct Person), sz, compare1);
	for (int i = 0; i < sz; i++)
	{
		printf("%s, %d\n", person[i].name,person[i].age);
	}
	return 0;
}