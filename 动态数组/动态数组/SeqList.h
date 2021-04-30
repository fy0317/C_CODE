#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
#define INITCAP 3
typedef struct SeqList
{
	DataType* arr;
	int size;
	int capacity;
}SeqList;
void InitSeqList(SeqList* p,int Capacity);		//��ʼ��˳���
void CheckSeqList(SeqList* p);					//���˳����Ƿ�Ϊ��������������
void SeqListPushFront(SeqList* p, DataType x);	//ͷ��
void SeqListPopFront(SeqList* p);		//ͷɾ
void PrintSeqList(SeqList* p);			//��ӡ
void SeqListPushBack(SeqList* p, DataType x);	//β��
void SeqListPopBack(SeqList* p);	//βɾ