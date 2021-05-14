#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
List MakeEmpty(List L);		//链表置空
int Isempty(List L);		//判断是否为空
int IsLast(Position p);		//判断是否为最后一个
Position Find(int x, List L);	//查找数据为x的节点
void Delete(int x, List L);		//删除数据为x的节点
Position FindPrevious(int x, List L);	//查找数据为x的前一个节点
void Insert(int x, List L, Position p);	//在p节点后面插入一个数据x
void DeleteList(List L);				//删除链表
void PrintNode(List L);					//打印链表
struct Node
{
	int data;
	Position next;
};