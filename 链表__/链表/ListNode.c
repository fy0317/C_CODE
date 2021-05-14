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

int Isempty(List L)		//判断是否为空
{
	return L->next == NULL;
}

int IsLast(Position p)  	//判断是否为最后一个
{
	return p->next == NULL;
}

Position Find(int x, List L)	//查找数据为x的节点
{
	if (L == NULL) return NULL;
	Position tmp = L->next;
	while (L != NULL && L->data != x)
	{
		L = L->next;
	}
	return L;
}
Position FindPrevious(int x, List L)	//查找数据为x的前一个节点
{
	if (L == NULL) return NULL;
	Position tmp = L;
	while (tmp->next != NULL && tmp->next->data != x)
	{
		tmp = tmp->next;
	}
	return tmp;
}
void Delete(int x, List L)		//删除数据为x的节点
{
	if (L == NULL)return;
	Position p = FindPrevious(x, L);
	PtrToNode tmp = p->next;
	p->next = tmp->next;
	free(tmp);
}
void Insert(int x, List L, Position p)	//在p节点后面插入一个数据x
{
	if (L == NULL || p == NULL) return;
	PtrToNode tmp = p->next;
	PtrToNode NewNode = malloc(sizeof(struct Node));
	NewNode->data = x;
	p->next = NewNode;
	NewNode->next = tmp;
}

void DeleteList(List L)				//删除链表
{
	if (L == NULL) return;
	MakeEmpty(L);
	free(L);
}

void PrintNode(List L)					//打印链表
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







