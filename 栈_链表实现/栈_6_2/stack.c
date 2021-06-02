#include"stack.h"
int IsEmpty(Stack S)
{
	return S->next == NULL;
}

Stack CreatStack()		//����һ����ջ
{
	Stack S = malloc(sizeof(struct Node));
	if (!S) return NULL;
	S->next = NULL;
	return S;
}

void MakeEmpty(Stack S)
{
	if (!S) return;
	while (!IsEmpty(S))
	{
		Pop(S);
	}
}
void Push(DataType x, Stack S)		//��ջ
{
	PtrToNode tmp = malloc(sizeof(struct Node));
	if (tmp == NULL) return;
	tmp->next = S->next;
	S->next = tmp;
	tmp->data = x;
}

DataType Top(Stack S)
{
	if (!IsEmpty(S))
		return S->next->data;
	else
	{
		printf("��ջ\n");
		return 0;
	}
}
void Pop(Stack S)			//��ջ
{
	if (!IsEmpty(S))
	{
		PtrToNode tmp = S->next;
		S->next = tmp->next;
		free(tmp);
	}
	else return;
}

