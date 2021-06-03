#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Person
{
	void* node;
	char name[20];
	int age;
}Person;
typedef struct LinkNode
{
	struct LinkNode* next;
}LinkNode;

typedef struct LQueue
{
	LinkNode pHeader;	//头节点
	int size;		//队列大小
	LinkNode* pTail; //尾节点指针
}LQueue;
typedef void* LinkQueue;

//初始化队列
LinkQueue init_LinkQueue();
//入队
void push_LinkQueue(LinkQueue queue, void* data);
//出队
void pop_LinkQueue(LinkQueue queue);
//返回队头
void* front_LinkQueue(LinkQueue queue);
//返回队尾
void* back_LinkQueue(LinkQueue queue);
//返回队列大小
int size_LinkQueue(LinkQueue queue);
//判断是否为空
int isEmpty(LinkQueue queue);
//销毁队列
void destory_LinkQueue(LinkQueue queue);