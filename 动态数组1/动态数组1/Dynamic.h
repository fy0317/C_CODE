#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INITCAP  5		//初始容量
typedef struct Dynamic
{
	void** pArr;			//维护动态开辟的数组（每个元素是void*），这样可以接收任意类型的数据
	int size;			//数组当前大小
	int capacity;		//数组容量
}Dynamic;

Dynamic* InitArr(int x);		//初始化数组
void Check(Dynamic* arr);			//检查数组容量
void Insert(Dynamic* arr, void* data, int pos);		//插入数据
void Print(Dynamic* arr, void (*PrintData)(void*));		//打印数组
void DeleteByPos(Dynamic* arr, int pos);			//根据位置删除数据
void DeleteByData(Dynamic* arr, void* data, int (*Compare)(void* p1,void* p2));		//根据数据删除数据
void DestroyArr(Dynamic* arr);		//销毁数组