#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

//创新一个新的结点
SL* CreadSListNode()
{
	SL* NewNode = (SL*)malloc(sizeof(SL));
	if (NewNode == NULL)
	{
		printf("申请失败\n");
		exit(-1);
	}
	return NewNode;
}
void PrintSList(SL* phead)		//打印链表
{
	if (phead == NULL) return;
	SL* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}


//头部插入
void SListPushFront(SL** pphead, SListDataType x)
{
	SL* ps = CreadSListNode();
	ps->next = *pphead;
	*pphead = ps;
	ps->data = x;
}

void SListPopFront(SL** pphead)						//头部删除
{
	if (*pphead == NULL) return;
	SL* cur = *pphead;
	*pphead = (*pphead)->next;
	free(cur);
	cur = NULL;
}

//尾部插入
void SListPushBack(SL** pphead, SListDataType x)
{
	SL* ps = CreadSListNode();
	if (*pphead == NULL)
	{
		*pphead = ps;

	}
	//else if ((*pphead)->next == NULL)
	//{
	//	(*pphead)->next = ps;
	//}
	else
	{
		SL* cur = *pphead;
		SL* pre = NULL;
		while (cur != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		pre->next = ps;
	}
	ps->data = x;
	ps->next = NULL;
}

//尾部删除
void SListPopBack(SL** pphead)
{
	if (*pphead == NULL) return;
	else if ((*pphead)->next == NULL) *pphead = NULL;
	else
	{
		SL* cur = *pphead;
		SL* pre = NULL;
		while (cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		free(cur);
		pre->next = NULL;
	}
}
//在n位后面插入x
void SListInsert(SL** pphead, int n, SListDataType x)
{
	int cnt = 0;
	if (n < 0)
	{
		printf("输入错误\n");
		return;
	}
	else if (n == 0)
	{
		SL* p = CreadSListNode();
		p->next = (*pphead);
		*pphead = p;
		p->data = x;
	}
	else
	{
		SL* p = CreadSListNode();
		SL* cur = *pphead;
		SL* pre = NULL;
		for (cnt = 0; cnt < n && cur != NULL; cnt++)
		{
			pre = cur;
			cur = cur->next;
		}
		if (cnt == n)
		{
			pre->next = p;
			p->next = cur;
			p->data = x;
		}
		else printf("输入错误\n");

	}
}

//删除第n位结点
void SListErase(SL** pphead, int n)
{
	if (*pphead == NULL) return;
	else if (n == 1)
	{

		SL* tmp = *pphead;
		*pphead = (*pphead)->next;
		free(tmp);
		tmp = NULL;
	}
	else
	{
		SL* Next = *pphead;
		SL* cur = *pphead;
		SL* pre = *pphead;
		int cnt = 0;
		while ((Next != NULL) && (cnt < n))
		{
			pre = cur;
			cur = Next;
			Next = Next->next;
			cnt++;
		}
 		if (cnt != n)
		{
			printf("输入错误\n");
			return;
		}
		pre->next = Next;
		free(cur);
		cur = NULL;

	}
}

