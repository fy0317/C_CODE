#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define MAX 2
typedef void* SeqQueue;
typedef struct Person
{
	char name[20];
	int age;
}Person;
typedef struct QueueRecord
{
	Person* arr;
	int size;
	int capacity;
}QueueRecord;
//初始化队列
SeqQueue Init_SeqQueue();
//入队
void push_SeqQueue(SeqQueue queue, void* data);
//出队
void pop_SeqQueue(SeqQueue queue);
//返回队头
void* front_SeqQueue(SeqQueue queue);
//返回队尾
void* back_SeqQueue(SeqQueue queue);
//返回队列大小
int size_SeqQueue(SeqQueue queue);
//判断队列是否为空
int IsEmpty(SeqQueue queue);
//销毁队列
void destroy_SeqQueue(SeqQueue queue);