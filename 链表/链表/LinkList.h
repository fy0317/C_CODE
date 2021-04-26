#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct LinkNode {
	int val;
	struct LinkNode* next;
}LinkNode;

LinkNode* InitLinkList();			//初始化链表并返回一个头节点
void foreach_LinkList(LinkNode* phead);					//遍历链表
void Insert(LinkNode* phead, int oldval, int newval);		//在数据等于oldval的节点前面插入数据为newval的节点
//删除数据为val的节点
void delet_LinkList(LinkNode* phead, int delval);
void clear_LinkList(LinkNode* phead);		//清空链表
void destory_LinkList(LinkNode** phead);		//销毁链表