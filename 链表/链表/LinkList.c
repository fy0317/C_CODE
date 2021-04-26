#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"
LinkNode* InitLinkList()			//��ʼ����������һ��ͷ�ڵ�
{
	LinkNode* phead = (LinkNode*)malloc(sizeof(LinkNode));
	if (phead == NULL) return phead;
	int n = 0;
	LinkNode* cur = phead;
	while (1)
	{
		printf("��������Ҫ���������:\n");
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
void foreach_LinkList(LinkNode* phead)					//��������
{
	if (phead == NULL) return;
	LinkNode* cur = phead->next;
	while (cur != NULL)
	{
		printf("%d\n", cur->val);
		cur = cur->next;
	}
}

//�����ݵ���oldval�Ľڵ�ǰ���������Ϊnewval�Ľڵ�
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
//ɾ������Ϊval�Ľڵ�
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
		printf("û�е�ǰԪ��\n");
		return;
	}
	prev->next = cur->next;
	free(cur);
	cur = NULL;
}
void clear_LinkList(LinkNode* phead)		//�������
{
	if (phead == NULL) return;
	LinkNode* cur = phead->next;
	while (cur != NULL)
	{
		//�ȼ�¼��һ���ڵ�λ��
		LinkNode* next = cur->next;
		free(cur);
		cur = next;
	}
	phead->next = NULL;

}
void destory_LinkList(LinkNode** phead)		//��������
{
	if (*phead == NULL)return;
	LinkNode* cur = (*phead)->next;
	while (cur != NULL)
	{
		//�ȼ�¼��һ���ڵ�λ��
		LinkNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(*phead);
	*phead = NULL;
}