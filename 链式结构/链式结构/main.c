#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

void Test1()
{
	SL* Phead = NULL;
	SListPushFront(&Phead, -3);
	SListPushFront(&Phead, -2);
	SListPushFront(&Phead, -1);
	SListPushBack(&Phead, 1);
	SListPushBack(&Phead, 2);
	SListPushBack(&Phead, 3);
	SListPrint(Phead);
	SL* pos = SListFind(Phead, 2);
	if (pos)
	{
		pos->data = 10;
	}
	SListPrint(Phead);

}
int main()
{
	Test1();
	return 0;
}