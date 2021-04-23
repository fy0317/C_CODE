#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

Test1()
{
	SL* phead = NULL;
	//SListPushFront(&phead, 10);
	//SListPushFront(&phead, 9);
	//SListPushFront(&phead, 8);
	//SListPushFront(&phead, 7);
	//SListPushFront(&phead, 6);
	//SListPushFront(&phead, 5);
	//PrintSList(phead);
	//printf("\n");
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	PrintSList(phead);
	printf("\n");
	int n = 0;
	scanf("%d", &n);
	SListInsert(&phead, n, 5);
	PrintSList(phead);
	printf("\n");
	scanf("%d", &n);
	SListErase(&phead, n);	//删除第n位结点
 	PrintSList(phead);



}
int main()
{
	Test1();
	return 0;
}