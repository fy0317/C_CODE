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

void SListPushFront(SL** pphead, SListDataType x);				//������ͷ������x
void SListPopFront(SL*);										//ͷ��ɾ��һ��Ԫ��
void PrintSList(SL* phead);		//��ӡ����
void SListPushBack(SL** pphead, SListDataType x);			//β������
void SListPopBack(SL** pphead);				//β������
void SListInsert(SL** pphead, int n, SListDataType x);		//��nλ�������x
void SListEras(SL** pphead, int n);				//ɾ����nλ���
