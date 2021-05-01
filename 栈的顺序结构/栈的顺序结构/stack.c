#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"

//初始化
SeqStack InitStack()
{
	Stack* My_stack = malloc(sizeof(Stack));
	if (My_stack == NULL) return NULL;
	memset(My_stack->data, 0, sizeof(void*) * MAX);
	My_stack->size = 0;
	return My_stack;
}

// 入栈(数组的尾插)
void PushStack(SeqStack stack, void* data)
{
	if (stack == NULL || data == NULL) return;
	Stack* My_stack = stack;
	if (My_stack->size == MAX) return;
	My_stack->data[My_stack->size] = data;
	My_stack->size++;

}

//出栈(数组的尾删)
void PopStack(SeqStack stack)
{
	if (stack == NULL) return;
	Stack* My_stack = stack;
	if (My_stack->size == 0) return;
	My_stack->data[My_stack->size - 1] = NULL;
	My_stack->size--;
}
//返回栈顶
void* TopStack(SeqStack stack)
{
	if (stack == NULL) return;
	Stack* My_stack = stack;
	if (My_stack->size == 0) return;
	return My_stack->data[My_stack->size - 1];
}
//返回栈的大小
int SizeStack(SeqStack stack)
{
	if (stack == NULL);
	Stack* My_stack = stack;
	return My_stack->size;
}
//判断栈是否为空
int Isempty(SeqStack stack)
{
	if (stack == NULL)return 0;
	Stack* My_stack = stack;
	if (My_stack->size == 0) return 1;//返回1表明为空
	return 0;;		//不为空
}
//销毁
void DestoryStack(SeqStack stack)
{
	if (stack == NULL)return;
	free(stack);
	stack = NULL;
}