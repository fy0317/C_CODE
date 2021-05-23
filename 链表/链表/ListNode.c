#define _CRT_SECURE_NO_WARNINGS
#include"ListNode.h"
List MakeEmpty(List L)
{
	if (L == NULL) return NULL;
	PtrToNode cur = L;
	PtrToNode next = L->next;
	while (next)
	{
		cur = next->next;
		free(next);
		next = cur;
	}
	L->next = NULL;
	return L;
}

int Isempty(List L)		//�ж��Ƿ�Ϊ��
{
	return L->next == NULL;
}

int IsLast(Position p)  	//�ж��Ƿ�Ϊ���һ��
{
	return p->next == NULL;
}

Position Find(int x, List L)	//��������Ϊx�Ľڵ�
{
	if (L == NULL) return NULL;
	Position tmp = L->next;
	while (L != NULL && L->data != x)
	{
		L = L->next;
	}
	return L;
}
Position FindPrevious(int x, List L)	//��������Ϊx��ǰһ���ڵ�
{
	if (L == NULL) return NULL;
	Position tmp = L;
	while (tmp->next != NULL && tmp->next->data != x)
	{
		tmp = tmp->next;
	}
	return tmp;
}
void Delete(int x, List L)		//ɾ������Ϊx�Ľڵ�
{
	if (L == NULL)return;
	Position p = FindPrevious(x, L);
	PtrToNode tmp = p->next;
	p->next = tmp->next;
	free(tmp);
}
void Insert(int x, List L, Position p)	//��p�ڵ�������һ������x
{
	if (L == NULL || p == NULL) return;
	PtrToNode tmp = p->next;
	PtrToNode NewNode = malloc(sizeof(struct Node));
	NewNode->data = x;
	p->next = NewNode;
	NewNode->next = tmp;
}

void DeleteList(List L)				//ɾ������
{
	if (L == NULL) return;
	MakeEmpty(L);
	free(L);
}

void PrintNode(List L)					//��ӡ����
{
	if (L == NULL)
		return;
	PtrToNode tmp = L->next;
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}







