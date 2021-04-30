#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
void test1()
{
	SeqList p;
	InitSeqList(&p, INITCAP);
	SeqListPushFront(&p, 1);
	SeqListPushFront(&p, 2);
	SeqListPushFront(&p, 3);
	SeqListPushFront(&p, 4);
	SeqListPushFront(&p, 5);
	PrintSeqList(&p);
	SeqListPopFront(&p);
	SeqListPopFront(&p);
	SeqListPopFront(&p);
	SeqListPopFront(&p);
	SeqListPopFront(&p);
	SeqListPopFront(&p);
	PrintSeqList(&p);
	SeqListPushBack(&p, 10);
	SeqListPushBack(&p, 9);
	SeqListPushBack(&p, 8);
	SeqListPushBack(&p, 7);
	PrintSeqList(&p);
	SeqListPopBack(&p);
	PrintSeqList(&p);

	SeqListPopBack(&p);
	PrintSeqList(&p);
	SeqListPopBack(&p);
	SeqListPopBack(&p);
	SeqListPopBack(&p);
	PrintSeqList(&p);



}
int main()
{
	test1();
	return 0;
}