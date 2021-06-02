#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int  DataType;
struct StackRecord
{
	int size;
	int capacity;
	DataType* data;
};
typedef struct StackRecord* Stack;
int IsEmpty(Stack S);	//�ж��Ƿ��ǿ�ջ
int IsFull(Stack S);	//�ж�ջ�Ƿ���
Stack CreatStack(int MaxSize);	//����һ��ջ
void DisposeStack(Stack S);		//����ջ
void Push(Stack S, DataType x);		//��ջ
DataType TopAndPop(Stack S);		//����ջ��,����ջ
void Pop(Stack S);		//��ջ
