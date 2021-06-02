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
int IsEmpty(Stack S);	//判断是否是空栈
int IsFull(Stack S);	//判断栈是否满
Stack CreatStack(int MaxSize);	//创建一个栈
void DisposeStack(Stack S);		//销毁栈
void Push(Stack S, DataType x);		//进栈
DataType TopAndPop(Stack S);		//返回栈顶,并出栈
void Pop(Stack S);		//出栈
