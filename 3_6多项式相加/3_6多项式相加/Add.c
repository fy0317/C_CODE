#include"Add.h"

#define len sizeof(LinkNode) 

//创建节点
LinkNode* CreatLinkNode()
{
	LinkNode* head, * p1, * p2;
	head = malloc(len);
	p1 = head, p2 = head;
	double data = 0;	//系数
	int my_index = 0;	//指数
	printf("输入系数及其对应的指数：\n");
	scanf("%lf %d", &data,&my_index);
	while (data)
	{
		p1->next = malloc(len);
		p1 = p1->next;
		p1->n = data;
		p1->index = my_index;
		scanf("%lf %d", &data, &my_index);
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

LinkNode* Add(const LinkNode* L1, const LinkNode* L2)
{
	if (L1 == NULL && L2 == NULL) return NULL;
	if (!L1->next) return L2;
	if (!L2->next) return L1;
	L1 = L1->next;
	L2 = L2->next;
	LinkNode* newnode = malloc(len);
	LinkNode* tmp = newnode;
	while (L1 && L2)
	{
		if (L1->index == L2->index)
		{
			tmp->next = malloc(len);
			tmp = tmp->next;
			tmp->index = L1->index;
			tmp->n = L1->n + L2->n;
			L1 = L1->next;
			L2 = L2->next;
		}
		else if (L1->index > L2->index)
		{
			tmp->next = malloc(len);
			tmp = tmp->next;
			tmp->index = L1->index;
			tmp->n = L1->n;
			L1 = L1->next;
		}
		else {
			tmp->next = malloc(len);
			tmp = tmp->next;
			tmp->index = L2->index;
			tmp->n = L2->n;
			L2 = L2->next;
		}
	}
	while (L1)
	{
		tmp->next = malloc(len);
		tmp = tmp->next;
		tmp->index = L1->index;
		tmp->n = L1->n;
		L1 = L1->next;
	}
	while (L2)
	{
		tmp->next = malloc(len);
		tmp = tmp->next;
		tmp->index = L2->index;
		tmp->n = L2->n;
		L2 = L2->next;
	}
	tmp->next = NULL;
	return newnode;
}

double Sum(const LinkNode* L, double x)
{
	if (L == NULL) return 0;
	LinkNode* tmp = L->next;
	double sum = 0;
	while (tmp)
	{
		sum += tmp->n* pow(x, tmp->index);
		tmp = tmp->next;
	}
	return sum;
}