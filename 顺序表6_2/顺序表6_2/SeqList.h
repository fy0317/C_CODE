#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 2
typedef int DataType;
typedef struct SeqList
{
	int size;
	int capacity;
	DataType* data;
}SeqList;

SeqList* Creat();
SeqList* Increase(SeqList* Seq);					//���Ӵ�С
int IsFull(SeqList* Seq);							//����Ƿ���
void SeqListPushFront(SeqList* Seq, DataType x);	//ͷ��
void SeqListPushBack(SeqList* Seq, DataType x);		//β��
void SeqListPopFront(SeqList* Seq);					//ͷɾ
void SeqListPopBack(SeqList* Seq);					//βɾ
void PrintSeq(const SeqList* Seq);		//��ӡ
