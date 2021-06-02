#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;


int IsEmpty(Stack S);
Stack CreatStack();				//创建一个空栈
void MakeEmpty(Stack S);			//栈置空
void Push(DataType x, Stack S);		//进栈
DataType Top(Stack S);		//返回栈顶元素
void Pop(Stack S);			//出栈

struct Node
{
	DataType data;
	PtrToNode next;
};