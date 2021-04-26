#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"
LinkNode* InitLinkList()			//初始化链表并返回一个头节点
{
	LinkNode* phead = (LinkNode*)malloc(sizeof(LinkNode));
	if (phead == NULL) return phead;
	int n = 0;
	LinkNode* cur = phead;
	while (1)
	{
		printf("请输入想要插入的数据:\n");
		scanf("%d", &n);
		if (n == -1) break;
		LinkNode* NewNode = (LinkNode*)malloc(sizeof(LinkNode));
		if (NewNode == NULL) break;
		cur->next = NewNode;
		cur = NewNode;
		NewNode->val = n;
		NewNode->next = NULL;
	}
	return phead;
}
void foreach_LinkList(LinkNode* phead)					//遍历链表
{
	if (phead == NULL) return;
	LinkNode* cur = phead->next;
	while (cur != NULL)
	{
		printf("%d\n", cur->val);
		cur = cur->next;
	}
}

//在数据等于oldval的节点前面插入数据为newval的节点
void Insert(LinkNode* phead, int oldval, int newval)
{
	if (!phead) return;
	LinkNode* prev = phead;
	LinkNode* cur = phead->next;
	while (cur!=NULL && cur->val != oldval)
	{
		prev = cur;
		cur = cur->next;
	}
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	if (newnode == NULL) return;
	newnode->val = newval;
	newnode->next = cur;
	prev->next = newnode;

}
//删除数据为val的节点
void delet_LinkList(LinkNode* phead, int delval)
{
	if (phead == NULL) return;
	LinkNode* prev = phead;
	LinkNode* cur = phead->next;
	while (cur != NULL && cur->val != delval)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL)
	{
		printf("没有当前元素\n");
		return;
	}
	prev->next = cur->next;
	free(cur);
	cur = NULL;
}
void clear_LinkList(LinkNode* phead)		//清空链表
{
	if (phead == NULL) return;
	LinkNode* cur = phead->next;
	while (cur != NULL)
	{
		//先记录下一个节点位置
		LinkNode* next = cur->next;
		free(cur);
		cur = next;
	}
	phead->next = NULL;

}
void destory_LinkList(LinkNode** phead)		//销毁链表
{
	if (*phead == NULL)return;
	LinkNode* cur = (*phead)->next;
	while (cur != NULL)
	{
		//先记录下一个节点位置
		LinkNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(*phead);
	*phead = NULL;
}