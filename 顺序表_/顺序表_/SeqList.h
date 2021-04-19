#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#define IniSz 10		//��ʼ������С
typedef int SeqDataType;

typedef struct SeqList
{
	SeqDataType* p;
	int sz;				//��ǰ��ŵ�Ԫ�ظ���
	int capacity;		//������С
}SL;

void SeqListInit(SL* ps);								//��ʼ��˳���
void CheckCapacity(SL* ps);								//�������
void PrintSeqList(const SL* ps);						//��ӡ˳���
void SeqListPushBack(SL* ps, SeqDataType x);			//β��
void SeqListPopBack(SL* ps);							//βɾ
void SeqListPushFront(SL* ps, SeqDataType x);			//ͷ��
void SeqListPopFront(SL* ps);							//ͷɾ
void SeqListInsert(SL* ps, int pos, SeqDataType x);		//����λ�ò���
void SeqListErase(SL* ps, int pos);						//����λ��ɾ��