#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int SListDataType;
typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
	
}SL,*Slist;

void SListPushFront(SL** pphead, SListDataType x);				//在链表头部插入x
void SListPopFront(SL*);										//头部删除一个元素
void PrintSList(SL* phead);		//打印链表
void SListPushBack(SL** pphead, SListDataType x);			//尾部插入
void SListPopBack(SL** pphead);				//尾部插入
void SListInsert(SL** pphead, int n, SListDataType x);		//在n位后面插入x
void SListEras(SL** pphead, int n);				//删除第n位结点
