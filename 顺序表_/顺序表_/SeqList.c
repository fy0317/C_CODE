#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"


//��ʼ��˳���
void SeqListInit(SL* ps)
{
	assert(ps);
	ps->p = (SeqDataType*)malloc(sizeof(SeqDataType) * IniSz);
	ps->sz = 0;
	ps->capacity = IniSz;
}

//�������
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


//��ӡ˳���
void PrintSeqList(const SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->p[i]);
	}
}

//β������
void SeqListPushBack(SL* ps, SeqDataType x)
{
	CheckCapacity(ps);
	ps->p[ps->sz] = x;
	ps->sz++;
}

//β��ɾ��
void SeqListPopBack(SL* ps)
{
	ps->sz--;
}

//ͷ������
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

//ͷ��ɾ��
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
//����λ�ò���
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
//����λ��ɾ��

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