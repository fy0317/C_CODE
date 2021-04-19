#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

SL s;
void TestInit()			//��ʼ������
{
	SeqListInit(&s);
}
void TestPushBack()		//β�����
{
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);

}
void TestPopBack()		//βɾ����
{
	SeqListPopBack(&s);
}
void TestPushFront()		//ͷ�����
{
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPushFront(&s, -4);
	SeqListPushFront(&s, -5);
	SeqListPushFront(&s, -6);

}

void TestPopFront()			//ͷɾ����
{
	SeqListPopFront(&s);
}

void TestInsert()			//����λ�ò������
{
	SeqListInsert(&s, 2, 9);
}

void TestErase()			//����λ��ɾ��
{
	SeqListErase(&s, 3);
}

int main()
{
	TestInit();
	TestPushBack();
	PrintSeqList(&s);
	printf("\n");
	//TestPushFront();
	//TestPopFront();
	//TestInsert();
	//PrintSeqList(&s);
	TestErase();
	PrintSeqList(&s);
	printf("\n");
	return 0;
}