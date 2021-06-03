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
//��ʼ������
SeqQueue Init_SeqQueue();
//���
void push_SeqQueue(SeqQueue queue, void* data);
//����
void pop_SeqQueue(SeqQueue queue);
//���ض�ͷ
void* front_SeqQueue(SeqQueue queue);
//���ض�β
void* back_SeqQueue(SeqQueue queue);
//���ض��д�С
int size_SeqQueue(SeqQueue queue);
//�ж϶����Ƿ�Ϊ��
int IsEmpty(SeqQueue queue);
//���ٶ���
void destroy_SeqQueue(SeqQueue queue);