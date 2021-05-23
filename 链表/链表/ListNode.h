#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
List MakeEmpty(List L);		//�����ÿ�
int Isempty(List L);		//�ж��Ƿ�Ϊ��
int IsLast(Position p);		//�ж��Ƿ�Ϊ���һ��
Position Find(int x, List L);	//��������Ϊx�Ľڵ�
void Delete(int x, List L);		//ɾ������Ϊx�Ľڵ�
Position FindPrevious(int x, List L);	//��������Ϊx��ǰһ���ڵ�
void Insert(int x, List L, Position p);	//��p�ڵ�������һ������x
void DeleteList(List L);				//ɾ������
void PrintNode(List L);					//��ӡ����
struct Node
{
	int data;
	Position next;
};