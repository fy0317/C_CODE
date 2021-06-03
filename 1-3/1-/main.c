#include"List.h"
void test3_1(const LinkNode* head);
void test3_2(const LinkNode* P, const LinkNode* L);
void PrintLots(const LinkNode* P, const LinkNode* L);
void test()
{
	LinkNode* head = malloc(sizeof(LinkNode));
	if (head != NULL)
	{
		head->next = NULL;
		head->val = 1;
	}
	else return;
	LinkNode p5 = { 31, NULL };
	LinkNode p4 = { 20, &p5 };
	LinkNode p3 = { 11, &p4 };
	LinkNode p2 = { 9, &p3 };
	LinkNode p1 = { 5, &p2 };
	LinkNode* head1 = malloc(sizeof(LinkNode));
	head1->val = 1;
	LinkNode L5 = { 9, NULL };
	LinkNode L4 = { 7, &L5 };
	LinkNode L3 = { 5, &L4 };
	LinkNode L2 = { 4, &L3 };
	LinkNode L1 = { 2, &L2 };
	head->next = &p1;
	head1->next = &L1;
	//test3_1(head);
	test3_2(head, head1);
	free(head);
}

//打印链表
void test3_1(const LinkNode* head)
{
	if (head == NULL)return;
	while (head)
	{
		printf("%d ", head->val);
		head = head->next;
	}
}

void test3_2(const LinkNode* P, const LinkNode* L)
{
	PrintLots(P, L);
}
void PrintLots(const LinkNode* P, const LinkNode* L)
{
	if (!P || !L)return;
	int cnt = 1;
	while (P)
	{
		if (cnt == L->val)
		{
			printf("%d ", P->val);
			L = L->next;
			P = P->next;
		}
		else P = P->next;
		cnt++;
	}
}
void PrintDoubleLinkNode1(const DoubleLinkNode* back)		//从后往前打印双链表
{
	while (back)
	{
		printf("%d ", back->val);
		back = back->pre;
	}
	printf("\n");
}

void PrintDoubleLinkNode(const DoubleLinkNode* head)		//顺序打印双链表
{
	while (head)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

void swap_double_LinkNode(DoubleLinkNode* p1, DoubleLinkNode* p2)
{
	if (p1 == NULL || p2 == NULL) return;
	p1->next = p2->next;
	if (p1->next)
		p1->next->pre = p1;
	p2->next = p1;
	p2->pre = p1->pre;
	if (p1->pre)
		p2->pre->next = p2;
	p1->pre = p2;

}
void test1()
{
	DoubleLinkNode* head = malloc(sizeof(DoubleLinkNode));
	head->pre = NULL;
	head->next = NULL;
	head->val = 0;
	DoubleLinkNode p5 = { NULL, NULL, 5 };
	DoubleLinkNode p4 = { NULL, NULL, 4 };
	DoubleLinkNode p3 = { NULL, NULL, 3 };
	DoubleLinkNode p2 = { NULL, NULL, 2 };
	DoubleLinkNode p1 = { NULL, NULL, 1 };
	head->next = &p1;
	p1.pre = head;
	p1.next = &p2;
	p2.pre = &p1;
	p2.next = &p3;
	p3.pre = &p2;
	p3.next = &p4;
	p4.pre = &p3;
	p4.next = &p5;
	p5.pre = &p4;
	p5.next = NULL;
	printf("交换前顺序打印：");
	PrintDoubleLinkNode(head);
	printf("交换前倒序打印：");
	PrintDoubleLinkNode1(&p5);
	swap_double_LinkNode(&p1, &p2);
	printf("交换后顺序打印：");
	PrintDoubleLinkNode(head);
	printf("交换后倒序打印：");
	PrintDoubleLinkNode1(&p5);
	free(head);
}

int main()
{
	//test();
	test1();
	return 0;
}
