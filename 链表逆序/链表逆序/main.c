#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct LinkList {
	int val;
	struct LinkList* next;
}LinkList;

//��ʼ������
void InitList(LinkList* phead)
{
	if (phead == NULL) return;
	LinkList* cur = phead->next;
	int i = 1;
	while (cur != NULL)
	{
		cur->val = i;
		cur = cur->next;
		i++;
	}
}
//��ӡ����
void  PrintList(LinkList* phead)
{
	if (phead == NULL) return;
	LinkList* cur = phead->next;
	while (cur != NULL)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}
//��ת���� ������ʵ�֣�
void ReverseList(LinkList* phead)
{
	if (phead == NULL || phead->next == NULL) return;
	LinkList* prev = NULL;
	LinkList* cur = phead->next;
	LinkList* next = cur->next;
	while (cur!=NULL)
	{
		cur->next = prev;
		prev = cur;
		cur = next;
		if(next !=NULL)
			next = next->next;
	}
	phead->next = prev;
	//return phead;
}
//��ת���� ���ݹ�ʵ�֣�
LinkList* ReverseList1(LinkList* phead)
{
	if (phead == NULL || phead->next == NULL) return phead;
	LinkList* Newhead =  ReverseList1(phead->next);
	phead->next->next = phead;
	phead->next= NULL;
	return Newhead;

}
int main()
{
	//��������ڵ�
	LinkList* phead = (LinkList*)malloc(sizeof(LinkList));
	LinkList* node1 = (LinkList*)malloc(sizeof(LinkList));
	LinkList* node2 = (LinkList*)malloc(sizeof(LinkList));
	LinkList* node3 = (LinkList*)malloc(sizeof(LinkList));
	LinkList* node4 = (LinkList*)malloc(sizeof(LinkList));
	LinkList* node5 = (LinkList*)malloc(sizeof(LinkList));
	//���������ϵ
	if(phead)
		phead->next = node1;
	if(node1)
		node1->next = node2;
	if(node2)
		node2->next = node3;
	if(node3)
		node3->next = node4;
	if(node4)


		node4->next = node5;
	if(node5)
		node5->next = NULL;
	//��ʼ������
	InitList(phead);
	//��ӡ����
	PrintList(phead);
	//��ת����������
	//ReverseList(phead);
	//printf("��ת��:\n");
	//PrintList(phead);
	//��ת�����ݹ飩
	LinkList* Newhead = malloc(sizeof(LinkList));
	if(Newhead)
		Newhead->next = ReverseList1(phead);
	//printf("%d", Newhead->val);
	printf("��ת��:\n");
	PrintList(Newhead);

	return 0;
}