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

//��ʼ��
SeqStack InitStack();
// ��ջ
void PushStack(SeqStack stack, void* data);
//��ջ
void PopStack(SeqStack stack);
//����ջ��
void* TopStack(SeqStack stack);
//����ջ�Ĵ�С
int SizeStack(SeqStack stack);
//�ж�ջ�Ƿ�Ϊ��
int Isempty(SeqStack stack);
//����
void DestoryStack(SeqStack stack);