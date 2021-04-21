#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int SListDataType;												//�����е���������

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SL, * LinkList;


bool SListPushFront(LinkList* pphead,SListDataType x );					//��ͷ�������µĽ��
bool SListPopFront(LinkList* pphead);										//��ͷ��ɾ��һ�����
bool SListPushBack(LinkList* pphead, SListDataType x);					//��β�������µĽ��
bool SListPopBack(LinkList* phead);										//��β��ɾ��һ�����
void SListPrint(LinkList phead);										//��ӡ��������
SL* BuySListNode();									//�½�һ�����
SL* SListFind(SL* phead, SListDataType x);			//��������Ϊx�Ľ��
