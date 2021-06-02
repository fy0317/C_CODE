#include"stack.h"

int IsEmpty(Stack S)	//�ж��Ƿ��ǿ�ջ
{
	if (S == NULL) return 0;
	return S->size == 0;
}

int IsFull(Stack S)	//�ж�ջ�Ƿ���
{
	return S->size == S->capacity;
}

Stack CreatStack(int MaxSize)	//����һ��ջ
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

void DisposeStack(Stack S)		//����ջ
{
	if (S)
	{
		free(S->data);
		free(S);
	}
}

void Push(Stack S, DataType x)		//��ջ
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
void Pop(Stack S)		//��ջ
{
	if (!IsEmpty(S))
	{
		S->size--;
	}
}

DataType TopAndPop(Stack S)		//����ջ��,����ջ
{
	if (!IsEmpty(S))
	{
		S->size--;
		return S->data[S->size];
	}
	else return 0;
}
