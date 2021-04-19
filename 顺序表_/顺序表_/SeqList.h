#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#define IniSz 10		//初始容量大小
typedef int SeqDataType;

typedef struct SeqList
{
	SeqDataType* p;
	int sz;				//当前存放的元素个数
	int capacity;		//容量大小
}SL;

void SeqListInit(SL* ps);								//初始化顺序表
void CheckCapacity(SL* ps);								//检查容量
void PrintSeqList(const SL* ps);						//打印顺序表
void SeqListPushBack(SL* ps, SeqDataType x);			//尾插
void SeqListPopBack(SL* ps);							//尾删
void SeqListPushFront(SL* ps, SeqDataType x);			//头插
void SeqListPopFront(SL* ps);							//头删
void SeqListInsert(SL* ps, int pos, SeqDataType x);		//任意位置插入
void SeqListErase(SL* ps, int pos);						//任意位置删除