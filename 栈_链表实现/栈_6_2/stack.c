#include"stack.h"
int IsEmpty(Stack S)
{
	return S->next == NULL;
}

Stack CreatStack()		//创建一个空栈
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
void Push(DataType x, Stack S)		//进栈
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
		printf("空栈\n");
		return 0;
	}
}
void Pop(Stack S)			//出栈
{
	if (!IsEmpty(S))
	{
		PtrToNode tmp = S->next;
		S->next = tmp->next;
		free(tmp);
	}
	else return;
}

