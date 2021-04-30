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
void InitSeqList(SeqList* p,int Capacity);		//初始化顺序表
void CheckSeqList(SeqList* p);					//检查顺序表是否为满，满了则扩容
void SeqListPushFront(SeqList* p, DataType x);	//头插
void SeqListPopFront(SeqList* p);		//头删
void PrintSeqList(SeqList* p);			//打印
void SeqListPushBack(SeqList* p, DataType x);	//尾插
void SeqListPopBack(SeqList* p);	//尾删