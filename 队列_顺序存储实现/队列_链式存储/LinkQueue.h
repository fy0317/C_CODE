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
	LinkNode pHeader;	//ͷ�ڵ�
	int size;		//���д�С
	LinkNode* pTail; //β�ڵ�ָ��
}LQueue;
typedef void* LinkQueue;

//��ʼ������
LinkQueue init_LinkQueue();
//���
void push_LinkQueue(LinkQueue queue, void* data);
//����
void pop_LinkQueue(LinkQueue queue);
//���ض�ͷ
void* front_LinkQueue(LinkQueue queue);
//���ض�β
void* back_LinkQueue(LinkQueue queue);
//���ض��д�С
int size_LinkQueue(LinkQueue queue);
//�ж��Ƿ�Ϊ��
int isEmpty(LinkQueue queue);
//���ٶ���
void destory_LinkQueue(LinkQueue queue);