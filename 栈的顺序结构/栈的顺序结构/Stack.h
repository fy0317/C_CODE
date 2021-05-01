#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024
typedef struct Stack
{
	void* data[MAX];
	int size;
}Stack;

typedef void* SeqStack;

//初始化
SeqStack InitStack();
// 入栈
void PushStack(SeqStack stack, void* data);
//出栈
void PopStack(SeqStack stack);
//返回栈顶
void* TopStack(SeqStack stack);
//返回栈的大小
int SizeStack(SeqStack stack);
//判断栈是否为空
int Isempty(SeqStack stack);
//销毁
void DestoryStack(SeqStack stack);