#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct LinkNode
{
	int val;
	struct LinkNode* next;
}LinkNode;


typedef struct DoubleLinkNode
{
	struct DoubleLinkNode* pre;
	struct DoubleLinkNode* next;
	int val;
}DoubleLinkNode;
