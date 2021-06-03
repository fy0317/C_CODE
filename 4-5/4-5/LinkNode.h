#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct LinkNode
{
	int val;
	struct LinkNode* next;
}LinkNode;

LinkNode* L1_And_L2(LinkNode* L1, LinkNode* L2);

LinkNode* L1_Or_L2(LinkNode* L1, LinkNode* L2);

void PrintLinkNode(const LinkNode* head);

LinkNode* CreatLinkNode();

void Destory(LinkNode* L);
