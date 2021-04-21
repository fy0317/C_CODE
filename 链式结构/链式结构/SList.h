#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int SListDataType;												//链表中的数据类型

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SL, * LinkList;


bool SListPushFront(LinkList* pphead,SListDataType x );					//在头部插入新的结点
bool SListPopFront(LinkList* pphead);										//在头部删除一个结点
bool SListPushBack(LinkList* pphead, SListDataType x);					//在尾部插入新的结点
bool SListPopBack(LinkList* phead);										//在尾部删除一个结点
void SListPrint(LinkList phead);										//打印链表数据
SL* BuySListNode();									//新建一个结点
SL* SListFind(SL* phead, SListDataType x);			//查找数组为x的结点
