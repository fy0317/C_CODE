#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"


//初始化顺序表
void SeqListInit(SL* ps)
{
	assert(ps);
	ps->p = (SeqDataType*)malloc(sizeof(SeqDataType) * IniSz);
	ps->sz = 0;
	ps->capacity = IniSz;
}

//检查容量
void CheckCapacity(SL* ps)
{
	if (ps->sz >= ps->capacity)
	{
		SeqDataType* tmp = (SeqDataType*)realloc(ps->p, sizeof(SeqDataType) * 2 * ps->capacity);
		assert(tmp);
		ps->p = tmp;
		ps->capacity *= 2;
	}
}


//打印顺序表
void PrintSeqList(const SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->p[i]);
	}
}

//尾部插入
void SeqListPushBack(SL* ps, SeqDataType x)
{
	CheckCapacity(ps);
	ps->p[ps->sz] = x;
	ps->sz++;
}

//尾部删除
void SeqListPopBack(SL* ps)
{
	ps->sz--;
}

//头部插入
void SeqListPushFront(SL* ps, SeqDataType x)
{
	CheckCapacity(ps);
	int i = 0;
	for (i = ps->sz; i > 0; i--)
	{
		ps->p[i] = ps->p[i - 1];
	}
	ps->p[0] = x;
	ps->sz++;
}

//头部删除
void SeqListPopFront(SL* ps)
{
	int i = 1;
	while (i < ps->sz )
	{
		ps->p[i - 1] = ps->p[i];
		i++;
	}
	ps->sz--;
}
//任意位置插入
void SeqListInsert(SL* ps, int pos, SeqDataType x)
{
	CheckCapacity(ps);
	if (pos < ps->sz)
	{
		int i = ps->sz-1;
		while (i >= pos)
		{
			ps->p[i + 1] = ps->p[i];
			i--;
		}
		ps->p[pos] = x;
		ps->sz++;
	}

}
//任意位置删除

void SeqListErase(SL* ps, int pos)
{
	if (pos < ps->sz)
	{
		int i = pos;
		while (i < ps->sz - 1)
		{
			ps->p[i] = ps->p[i + 1];
			i++;
		}
		ps->sz--;
	}
}