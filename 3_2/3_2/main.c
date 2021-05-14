#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
void PrintLots(Node*L, Node* P)
{
	if (L == NULL || P == NULL)
		return;
	int cnt = 0;
	Node* pl = L->next;
	Node* pp = P->next;
	while (pp && pl)
	{
		cnt++;
		if (pl == NULL)break;
		if (cnt == pp->data)
		{
			pp = pp->next;
			printf("%d ", pl->data);
		}
		pl = pl->next;
	}
}
int main()
{
	//Node* L = malloc(sizeof(Node));
	//Node* L1 = malloc(sizeof(Node));
	//Node* L2 = malloc(sizeof(Node));
	//Node* L3 = malloc(sizeof(Node));
	//L->next = L1;
	//L1->next = L2;
	//L1->data = 1;
	//L2->next = L3;
	//L2->data = 3;
	//L3->next = NULL;
	//L3->data = 6;
	//Node* P = malloc(sizeof(Node));
	//Node* P1 = malloc(sizeof(Node));
	//Node* P2 = malloc(sizeof(Node));
	//Node* P3 = malloc(sizeof(Node));
	//Node* P4 = malloc(sizeof(Node));
	//Node* P5 = malloc(sizeof(Node));
	//P->next = P1;
	//P1->next = P2;
	//P2->next = P3;
	//P3->next = P4;
	//P4->next = P5;
	//P5->next = NULL;
	//P1->data = 9;
	//P2->data = 13;
	//P3->data = 15;
	//P4->data = 21;
	//P5->data = 22;
	//PrintLots(P, L);
	Node* P[4];
	Node* L[6];
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		P[i] = malloc(sizeof(Node));
	}
	for (i = 0; i < 6; i++)
	{
		L[i] = malloc(sizeof(Node));
	}
	for (i = 0; i < 3; i++)
	{
		P[i]->next = P[i + 1];
		P[i + 1]->data = i + 1;
	}
	P[i]->next = NULL;
	for (i = 0; i < 5; i++)
	{
		L[i]->next = L[i + 1];
		L[i + 1]->data = 9 * i;
	}
	L[i]->next = NULL;
	PrintLots(L, P);
	for (i = 0; i < 4; i++)
	{
		free(P[i]);
	}
	for (i = 0; i < 6; i++)
	{
		free(L[i]);
	}
	return 0;
}


