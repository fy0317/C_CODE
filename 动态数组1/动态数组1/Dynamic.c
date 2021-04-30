#define _CRT_SECURE_NO_WARNINGS
#include"Dynamic.h"
Dynamic* InitArr(int x)		//��ʼ������,��ʼ������Ϊx
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
void Insert(Dynamic* arr, void* data, int pos)		//��������
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
void Print(Dynamic* arr, void (*PrintData)(void*))		//��ӡ����
{
	if (arr == NULL) return;
	for (int i = 0; i < arr->size; i++)
	{
		PrintData(arr->pArr[i]);
	}
}
void DeleteByPos(Dynamic* arr, int pos)			//����λ��ɾ������
{
	if (arr == NULL || arr->size == 0) return;
	if (pos < 0 || pos >= arr->size)			//������Χǿ��βɾ
		pos = arr->size - 1;
	for (int i = pos; i < arr->size; i++)
	{
		arr->pArr[i] = arr->pArr[i + 1];
	}
	arr->size--;
}
void DeleteByData(Dynamic* arr, void* data,int (*Compare)(void*,void*) )		//��������ɾ������
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
	printf("û����Ҫɾ��������\n");
}
void DestroyArr(Dynamic* arr)		//��������
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
