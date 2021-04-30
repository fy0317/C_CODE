#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
void InitSeqList(SeqList* p, int Capacity)
{
	if (p == NULL) return;
	p->arr = (DataType*)malloc(sizeof(DataType) * Capacity);
	if (p->arr == NULL) return;
	p->capacity = Capacity;
	p->size = 0;
}
void CheckSeqList(SeqList* p)					//���˳����Ƿ�Ϊ��
{
	if (p == NULL) return;
	if (p->size >= p->capacity)
	{
		DataType* tmp = realloc(p->arr, sizeof(DataType)* 2 * p->capacity);
		if (tmp == NULL) return;
		p->arr = tmp;
		p->capacity *= 2;
	}
}
void PrintSeqList(SeqList* p)			//��ӡ
{
	for (int i = 0; i < p->size; i++)
	{
		printf("%d ", (p->arr)[i]);
	}
	printf("\n");
}
void SeqListPushFront(SeqList* p, DataType x)	//ͷ��
{
	CheckSeqList(p);
	for (int i = p->size -1; i>=0; i--)
	{
		(p->arr)[i + 1] = (p->arr)[i];
	}
	p->arr[0] = x;
	p->size++;
}
void SeqListPopFront(SeqList* p)		//ͷɾ
{
	if (p == NULL) return;
	if (p->size > 0)
	{
		for (int i = 0; i < p->size - 1; i++)
		{
			p->arr[i] = p->arr[i + 1];
		}
		p->size--;
	}

}
void SeqListPushBack(SeqList* p, DataType x)	//β��
{
	if (p == NULL) return;
	CheckSeqList(p);
	p->arr[p->size] = x;
	p->size++;
}
void SeqListPopBack(SeqList* p)	//βɾ
{
	if (p->size > 0)
		p->size--;
}