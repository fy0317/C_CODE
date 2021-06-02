
#include"SeqList.h"


void test1()
{
	SeqList* Seq = Creat();
	SeqListPushFront(Seq, 1);
	SeqListPushFront(Seq, 2);
	SeqListPushFront(Seq, 3);
	SeqListPushFront(Seq, 4);
	PrintSeq(Seq);
	SeqListPushBack(Seq, 10);
	SeqListPushBack(Seq, 9);
	SeqListPushBack(Seq, 8);
	PrintSeq(Seq);
	SeqListPopBack(Seq);
	SeqListPopBack(Seq);
	SeqListPopBack(Seq);
	SeqListPopBack(Seq);
	SeqListPopBack(Seq);
	SeqListPopBack(Seq);	
	PrintSeq(Seq);

}

int main()
{
	test1();
	return 0;
}

