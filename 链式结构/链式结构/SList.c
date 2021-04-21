#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

//��ӡ��������
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
SL* BuySListNode()								//�½�һ�����
{
	SL* NewNode = (SL*)malloc(sizeof(SL));
	if (NewNode == NULL)
	{
		printf("����ʧ��\n");
		exit(-1);
	}
	return NewNode;
	

}


//ͷ��������
bool SListPushFront(LinkList* pphead, SListDataType x) 
{
	SL* ps = BuySListNode();
	ps->next = *pphead;
	*pphead = ps;
	ps->data = x;
	return true;
}
//ͷ��ɾ�����
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


//β��������
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

//β��ɾ�����
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
//��������Ϊx�Ľ��
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
