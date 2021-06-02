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
SeqList* Increase(SeqList* Seq);					//增加大小
int IsFull(SeqList* Seq);							//检查是否满
void SeqListPushFront(SeqList* Seq, DataType x);	//头插
void SeqListPushBack(SeqList* Seq, DataType x);		//尾插
void SeqListPopFront(SeqList* Seq);					//头删
void SeqListPopBack(SeqList* Seq);					//尾删
void PrintSeq(const SeqList* Seq);		//打印
