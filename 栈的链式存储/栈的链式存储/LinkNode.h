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
	LinkNode phead;		//ͷ�ڵ�
	int size;		//ջ�Ĵ�С
}Lstack;
typedef void* LinkStack;

//��ʼ��ջ
LinkStack Init_Linkstack();		

//��ջ
void Push_Linkstack(LinkStack stack, void* data);

//��ջ
void Pop_Linkstack(LinkStack stack);

//����ջ��
void* top_Linkstack(LinkStack stack);

//����ջ�Ĵ�С
int Size_Linkstack(LinkStack stack);

//�ж�ջ�Ƿ�Ϊ��
int Isempty(LinkStack stack);

//����ջ
void Destory(LinkStack stack);