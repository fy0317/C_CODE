#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;


int IsEmpty(Stack S);
Stack CreatStack();				//����һ����ջ
void MakeEmpty(Stack S);			//ջ�ÿ�
void Push(DataType x, Stack S);		//��ջ
DataType Top(Stack S);		//����ջ��Ԫ��
void Pop(Stack S);			//��ջ

struct Node
{
	DataType data;
	PtrToNode next;
};