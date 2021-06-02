#include"stack.h"

int IsEmpty(Stack S)	//判断是否是空栈
{
	if (S == NULL) return 0;
	return S->size == 0;
}

int IsFull(Stack S)	//判断栈是否满
{
	return S->size == S->capacity;
}

Stack CreatStack(int MaxSize)	//创建一个栈
{
	Stack S = malloc(sizeof(struct StackRecord));
	if (S == NULL) return NULL;
	S->data = malloc(sizeof(DataType) * MaxSize);
	if (!S->data)
	{
		free(S);
		return NULL;
	}
	S->size = 0;
	S->capacity = MaxSize;
	return S;
}

void DisposeStack(Stack S)		//销毁栈
{
	if (S)
	{
		free(S->data);
		free(S);
	}
}

void Push(Stack S, DataType x)		//进栈
{
	if (!S) return;
	if (IsFull(S))
	{
		DataType* tmp = realloc(S->data, sizeof(DataType) * S->capacity * 2);
		if (tmp)
		{
			S->data = tmp;
			S->capacity *= 2;
		}
		else return;
	}
	S->data[S->size] = x;
	S->size++;
}
void Pop(Stack S)		//出栈
{
	if (!IsEmpty(S))
	{
		S->size--;
	}
}

DataType TopAndPop(Stack S)		//返回栈顶,并出栈
{
	if (!IsEmpty(S))
	{
		S->size--;
		return S->data[S->size];
	}
	else return 0;
}
