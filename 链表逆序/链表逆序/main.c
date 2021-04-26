#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct LinkList {
	int val;
	struct LinkList* next;
}LinkList;

//初始化链表
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
//打印链表
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
//反转链表 （迭代实现）
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
//反转链表 （递归实现）
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
	//创建链表节点
	LinkList* phead = (LinkList*)malloc(sizeof(LinkList));
	LinkList* node1 = (LinkList*)malloc(sizeof(LinkList));
	LinkList* node2 = (LinkList*)malloc(sizeof(LinkList));
	LinkList* node3 = (LinkList*)malloc(sizeof(LinkList));
	LinkList* node4 = (LinkList*)malloc(sizeof(LinkList));
	LinkList* node5 = (LinkList*)malloc(sizeof(LinkList));
	//建立链表关系
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
	//初始化链表
	InitList(phead);
	//打印链表
	PrintList(phead);
	//反转链表（迭代）
	//ReverseList(phead);
	//printf("反转后:\n");
	//PrintList(phead);
	//反转链表（递归）
	LinkList* Newhead = malloc(sizeof(LinkList));
	if(Newhead)
		Newhead->next = ReverseList1(phead);
	//printf("%d", Newhead->val);
	printf("反转后:\n");
	PrintList(Newhead);

	return 0;
}