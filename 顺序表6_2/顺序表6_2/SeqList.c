#include"SeqList.h"
SeqList* Creat()
{
	SeqList* Seq = malloc(sizeof(SeqList));
	if (!Seq) return NULL;
	Seq->data = malloc(SIZE * sizeof(int));
	if (!Seq->data)
	{
		free(Seq);
		return NULL;
	}
	Seq->size = 0;
	Seq->capacity = SIZE;
	return Seq;
}

int IsFull(SeqList* Seq)							//����Ƿ���
{
	return Seq->size == Seq->capacity;
}

SeqList* Increase(SeqList* Seq)					//���Ӵ�С
{
	DataType* tmp = realloc(Seq->data, sizeof(int) * Seq->capacity * 2);
	if (tmp)
	{
		Seq->data = tmp;
		Seq->capacity *= 2;
	}
	else return NULL;
	return Seq;
}

void SeqListPushFront(SeqList* Seq, DataType x)	//ͷ��
{
	if (IsFull(Seq))
	{
		Seq = Increase(Seq);
	}
	for (int i = Seq->size - 1; i >= 0; i--)
	{
		Seq->data[i + 1] = Seq->data[i];
	}
	Seq->data[0] = x;
	Seq->size++;
}

void SeqListPopFront(SeqList* Seq)				//ͷɾ
{
	if (Seq->size == 0) return;
	for (int i = 0; i < Seq->size - 1; i++)
	{
		Seq->data[i] = Seq->data[i + 1];
	}
	Seq->size--;
}

void SeqListPushBack(SeqList* Seq, DataType x)		//β��
{
	if (IsFull(Seq))
	{
		Seq = Increase(Seq);
	}
	Seq->data[Seq->size] = x;
	Seq->size++;
}

void SeqListPopBack(SeqList* Seq)					//βɾ
{
	if (Seq->size == 0) return;
	Seq->size--;
}

void PrintSeq(const SeqList* Seq)		//��ӡ
{
	for (int i = 0; i < Seq->size; i++)
		printf("%d ", Seq->data[i]);
	printf("\n");
}