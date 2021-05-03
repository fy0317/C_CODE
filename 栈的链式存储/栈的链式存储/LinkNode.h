#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct LinkNode
{
	struct LinkNode* next;
}LinkNode;
typedef struct Lstack
{
	LinkNode phead;		//头节点
	int size;		//栈的大小
}Lstack;
typedef void* LinkStack;

//初始化栈
LinkStack Init_Linkstack();		

//入栈
void Push_Linkstack(LinkStack stack, void* data);

//出栈
void Pop_Linkstack(LinkStack stack);

//返回栈顶
void* top_Linkstack(LinkStack stack);

//返回栈的大小
int Size_Linkstack(LinkStack stack);

//判断栈是否为空
int Isempty(LinkStack stack);

//销毁栈
void Destory(LinkStack stack);