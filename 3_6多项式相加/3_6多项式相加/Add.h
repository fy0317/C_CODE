#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct LinkNode
{
	double n;
	int index;
	struct LinkNode* next;
}LinkNode;

LinkNode* CreatLinkNode();

LinkNode* Add(const LinkNode* L1, const LinkNode* L2);
double Sum(const LinkNode* L, double x);
void Destory(LinkNode* L);
