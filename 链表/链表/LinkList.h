#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct LinkNode {
	int val;
	struct LinkNode* next;
}LinkNode;

LinkNode* InitLinkList();			//��ʼ����������һ��ͷ�ڵ�
void foreach_LinkList(LinkNode* phead);					//��������
void Insert(LinkNode* phead, int oldval, int newval);		//�����ݵ���oldval�Ľڵ�ǰ���������Ϊnewval�Ľڵ�
//ɾ������Ϊval�Ľڵ�
void delet_LinkList(LinkNode* phead, int delval);
void clear_LinkList(LinkNode* phead);		//�������
void destory_LinkList(LinkNode** phead);		//��������