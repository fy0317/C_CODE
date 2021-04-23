#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

//����һ���µĽ��
SL* CreadSListNode()
{
	SL* NewNode = (SL*)malloc(sizeof(SL));
	if (NewNode == NULL)
	{
		printf("����ʧ��\n");
		exit(-1);
	}
	return NewNode;
}
void PrintSList(SL* phead)		//��ӡ����
{
	if (phead == NULL) return;
	SL* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}


//ͷ������
void SListPushFront(SL** pphead, SListDataType x)
{
	SL* ps = CreadSListNode();
	ps->next = *pphead;
	*pphead = ps;
	ps->data = x;
}

void SListPopFront(SL** pphead)						//ͷ��ɾ��
{
	if (*pphead == NULL) return;
	SL* cur = *pphead;
	*pphead = (*pphead)->next;
	free(cur);
	cur = NULL;
}

//β������
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

//β��ɾ��
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
//��nλ�������x
void SListInsert(SL** pphead, int n, SListDataType x)
{
	int cnt = 0;
	if (n < 0)
	{
		printf("�������\n");
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
		else printf("�������\n");

	}
}

//ɾ����nλ���
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
			printf("�������\n");
			return;
		}
		pre->next = Next;
		free(cur);
		cur = NULL;

	}
}

