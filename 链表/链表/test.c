#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"
void test1()
{
	LinkNode* phead = InitLinkList();			//��ʼ����������һ��ͷ�ڵ�
	foreach_LinkList(phead);					//��������
	Insert(phead, 23, 11);						//�����½ڵ�
	printf("�����½ڵ��\n");
	foreach_LinkList(phead);					//��������
	delet_LinkList(phead, 99);					//ɾ���ڵ�
	printf("ɾ���ڵ��\n");
	foreach_LinkList(phead);					//��������
	clear_LinkList(phead);
	printf("����ڵ��\n");
	foreach_LinkList(phead);					//��������
	destory_LinkList(&phead);					//��������
	Insert(phead, 23, 11);						//�����½ڵ�



}
int main()
{
	test1();
	return 0;
}