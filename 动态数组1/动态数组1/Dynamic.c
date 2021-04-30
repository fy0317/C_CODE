#define _CRT_SECURE_NO_WARNINGS
#include"Dynamic.h"
Dynamic* InitArr(int x)		//初始化数组,初始化容量为x
{
	if (x <= 0) return NULL;
	Dynamic* arr =(Dynamic*)malloc(sizeof(Dynamic));
	if (arr != NULL)
	{
		arr->pArr =(void**)malloc(sizeof(void*) * x);
		arr->capacity = x;
		arr->size = 0;
	}
	return arr;
}
void Check(Dynamic* arr)
{
	if (arr == NULL)
		return;
	if (arr->size >= arr->capacity)
	{
		Dynamic* tmp = (Dynamic*)realloc(arr, arr->capacity * 2);
		if (tmp == NULL) return;
		arr = tmp;
		arr->capacity *= 2;
	}
}
void Insert(Dynamic* arr, void* data, int pos)		//插入数据
{
	if (arr == NULL) return;
	if (pos < 0 || pos > arr->size)
		pos = arr->size;
	Check(arr);
	for (int i = arr->size; i >= pos; i--)
	{
		arr->pArr[i + 1] = arr->pArr[i];
	}
	arr->pArr[pos] = data;
	arr->size++;
}
void Print(Dynamic* arr, void (*PrintData)(void*))		//打印数组
{
	if (arr == NULL) return;
	for (int i = 0; i < arr->size; i++)
	{
		PrintData(arr->pArr[i]);
	}
}
void DeleteByPos(Dynamic* arr, int pos)			//根据位置删除数据
{
	if (arr == NULL || arr->size == 0) return;
	if (pos < 0 || pos >= arr->size)			//超出范围强制尾删
		pos = arr->size - 1;
	for (int i = pos; i < arr->size; i++)
	{
		arr->pArr[i] = arr->pArr[i + 1];
	}
	arr->size--;
}
void DeleteByData(Dynamic* arr, void* data,int (*Compare)(void*,void*) )		//根据数据删除数据
{
	if (arr == NULL || arr->size == 0 || data == NULL) return;
	for (int i = 0; i < arr->size; i++)
	{
		if (Compare(arr->pArr[i],data))
		{
			DeleteByPos(arr, i);
			return;
		}
	}
	printf("没有想要删除的数据\n");
}
void DestroyArr(Dynamic* arr)		//销毁数组
{
	if (arr == NULL) return;
	if (arr->pArr != NULL)
	{
		free(arr->pArr);
		arr->pArr = NULL;
	}
	free(arr);
	arr = NULL;
}
