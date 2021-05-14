#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//µ¥Á´±í
typedef struct SingleNode
{
	int data;
	struct Node* next;
}Node;
void swap1(Node* Before, Node* L)
{
	if (Before == NULL || L == NULL) return;
	Node* cur = Before->next;
	Node* Next = cur->next;
	cur->next = Next->next;;
	Before->next = Next;
	Next->next = cur;
}

//Ë«Á´±í
typedef struct DoubleNode
{
	int data;
	struct DoubleNode* next;
	struct DoubleNode* pre;
}Node1;
void swap(Node1* cur, Node1* L)
{
	if (!cur || !L)
		return;
	Node1* Before = cur->pre;
	Node1* Next = cur->next;
	cur->next = Next->next;
	cur->pre = Next;
	Before->next = Next;
	Next->pre = Before;
	
}