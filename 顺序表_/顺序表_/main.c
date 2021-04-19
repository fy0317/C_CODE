#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

SL s;
void TestInit()			//≥ı ºªØ≤‚ ‘
{
	SeqListInit(&s);
}
void TestPushBack()		//Œ≤≤Â≤‚ ‘
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
void TestPopBack()		//Œ≤…æ≤‚ ‘
{
	SeqListPopBack(&s);
}
void TestPushFront()		//Õ∑≤Â≤‚ ‘
{
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPushFront(&s, -4);
	SeqListPushFront(&s, -5);
	SeqListPushFront(&s, -6);

}

void TestPopFront()			//Õ∑…æ≤‚ ‘
{
	SeqListPopFront(&s);
}

void TestInsert()			//»Œ“‚Œª÷√≤Â»Î≤‚ ‘
{
	SeqListInsert(&s, 2, 9);
}

void TestErase()			//»Œ“‚Œª÷√…æ≥˝
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