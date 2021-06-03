#include"LinkNode.h"
#define len sizeof(struct LinkNode)
LinkNode* L1_And_L2(LinkNode* L1, LinkNode* L2)
{
	if (!L1 || !L2) return NULL;	
	L1 = L1->next;
	L2 = L2->next;
	if (!L1 || !L2) return NULL;	//L1，L2有一个为空表，返回空
	LinkNode* newnode = malloc(sizeof(LinkNode));
	if (newnode == NULL) return NULL;
	LinkNode* tmp = newnode;
	while (L1 && L2)
	{
		if (L1->val == L2->val)
		{
			tmp->next = malloc(len);
			tmp = tmp->next;
			tmp->val = L1->val;
			L1 = L1->next;
			L2 = L2->next;
		}
		else
		{
			if (L1->val > L2->val)
				L2 = L2->next;
			else L1 = L1->next;
		}
	}
	tmp->next = NULL;
	return newnode;
}
LinkNode* L1_Or_L2(LinkNode* L1, LinkNode* L2)
{
	if (L1 == NULL || L2 == NULL)
		return NULL;

	if (!L1->next) return L2;	//L1为空表，返回L2
	if (!L2->next) return L1;	//L2为空，但L1不为空表，返回L1
	L1 = L1->next;
	L2 = L2->next;
	//L1，L2均不为空
	LinkNode* newnode = malloc(sizeof(LinkNode));
	if (newnode == NULL) return NULL;
	LinkNode* tmp = newnode;
	while (L1 && L2)
	{
		if (L1->val > L2->val)
		{
			tmp->next = malloc(len);
			tmp = tmp->next;
			tmp->val = L2->val;
			L2 = L2->next;
		}
		else if (L1->val < L2->val)
		{
			tmp->next = malloc(len);
			tmp = tmp->next;
			tmp->val = L1->val;
			L1 = L1->next;
		}
		else
		{
			tmp->next = malloc(len);
			tmp = tmp->next;
			tmp->val = L2->val;
			L1 = L1->next;
			L2 = L2->next;
		}
	}
	while (L1)
	{
		tmp->next = malloc(len);
		tmp = tmp->next;
		tmp->val = L1->val;
		L1 = L1->next;
	}
	while (L2)
	{
		tmp->next = malloc(len);
		tmp = tmp->next;
		tmp->val = L2->val;
		L2 = L2->next;
	}
	tmp->next = NULL;
	return newnode;
}


//打印链表
void PrintLinkNode(const LinkNode* head)
{
	if (head == NULL)return;
	head = head->next;
	while (head)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

//创建节点
LinkNode* CreatLinkNode()
{
	LinkNode* head, *p1, *p2;
	head = malloc(len);
	p1 = head, p2 = head;
	int data = 0;
	scanf("%d", &data);
	while (data!= -1)
	{
		p1->next = malloc(len);
		p1 = p1->next;
		p1->val = data;
		scanf("%d", &data);
	}
	p1->next = NULL;
	return head;
}

void Destory(LinkNode* L)
{
	LinkNode* curr = L->next;
	LinkNode* next = curr;

	while (next)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(L);
}