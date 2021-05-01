#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"

//��ʼ��
SeqStack InitStack()
{
	Stack* My_stack = malloc(sizeof(Stack));
	if (My_stack == NULL) return NULL;
	memset(My_stack->data, 0, sizeof(void*) * MAX);
	My_stack->size = 0;
	return My_stack;
}

// ��ջ(�����β��)
void PushStack(SeqStack stack, void* data)
{
	if (stack == NULL || data == NULL) return;
	Stack* My_stack = stack;
	if (My_stack->size == MAX) return;
	My_stack->data[My_stack->size] = data;
	My_stack->size++;

}

//��ջ(�����βɾ)
void PopStack(SeqStack stack)
{
	if (stack == NULL) return;
	Stack* My_stack = stack;
	if (My_stack->size == 0) return;
	My_stack->data[My_stack->size - 1] = NULL;
	My_stack->size--;
}
//����ջ��
void* TopStack(SeqStack stack)
{
	if (stack == NULL) return;
	Stack* My_stack = stack;
	if (My_stack->size == 0) return;
	return My_stack->data[My_stack->size - 1];
}
//����ջ�Ĵ�С
int SizeStack(SeqStack stack)
{
	if (stack == NULL);
	Stack* My_stack = stack;
	return My_stack->size;
}
//�ж�ջ�Ƿ�Ϊ��
int Isempty(SeqStack stack)
{
	if (stack == NULL)return 0;
	Stack* My_stack = stack;
	if (My_stack->size == 0) return 1;//����1����Ϊ��
	return 0;;		//��Ϊ��
}
//����
void DestoryStack(SeqStack stack)
{
	if (stack == NULL)return;
	free(stack);
	stack = NULL;
}