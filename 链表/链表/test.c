#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"
void test1()
{
	LinkNode* phead = InitLinkList();			//初始化链表并返回一个头节点
	foreach_LinkList(phead);					//遍历链表
	Insert(phead, 23, 11);						//插入新节点
	printf("插入新节点后\n");
	foreach_LinkList(phead);					//遍历链表
	delet_LinkList(phead, 99);					//删除节点
	printf("删除节点后\n");
	foreach_LinkList(phead);					//遍历链表
	clear_LinkList(phead);
	printf("清除节点后\n");
	foreach_LinkList(phead);					//遍历链表
	destory_LinkList(&phead);					//销毁链表
	Insert(phead, 23, 11);						//插入新节点



}
int main()
{
	test1();
	return 0;
}