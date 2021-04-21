#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

//打印链表数据
void SListPrint(LinkList phead)									
{
	SL* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
SL* BuySListNode()								//新建一个结点
{
	SL* NewNode = (SL*)malloc(sizeof(SL));
	if (NewNode == NULL)
	{
		printf("申请失败\n");
		exit(-1);
	}
	return NewNode;
	

}


//头部插入结点
bool SListPushFront(LinkList* pphead, SListDataType x) 
{
	SL* ps = BuySListNode();
	ps->next = *pphead;
	*pphead = ps;
	ps->data = x;
	return true;
}
//头部删除结点
bool SListPopFront(LinkList* pphead)				
{
	if (*pphead == NULL) return false;
	else
	{
		SL* cur = *pphead;
		*pphead = (*pphead)->next;
		free(cur);
	}
	return true;
}


//尾部插入结点
bool SListPushBack(LinkList* pphead, SListDataType x)					
{
	LinkList cur = *pphead; 
	SL* ps = BuySListNode();
	if (*pphead == NULL)
	{
		*pphead = ps;
		ps->data = x;
		ps->next = NULL;
		return true;
	}
	else
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
	}
	cur->next = ps;
	ps->data = x;
	ps->next = NULL;
	return true;
}

//尾部删除结点
bool SListPopBack(LinkList* pphead)
{
	SL* cur = *pphead;
	if (cur == NULL) return false;
	else if (cur->next == NULL)
	{
		free((*pphead)->next);
		(*pphead) = NULL;
	}
	else
	{
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
	}
	free(cur->next);
	cur->next = NULL;
	return true;
}
//查找数组为x的结点
SL* SListFind(SL* phead, SListDataType x)
{
	SL* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x) return cur;
		else cur = cur->next;
	}
	return NULL;
}
