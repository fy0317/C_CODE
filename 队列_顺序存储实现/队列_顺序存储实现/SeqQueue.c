#include"SeqQueue.h"

//��ʼ������
SeqQueue Init_SeqQueue()
{
	QueueRecord* queue = malloc(sizeof(QueueRecord));
	if (queue == NULL) return NULL;
	queue->arr = malloc(sizeof(Person) * MAX);
	if (queue->arr == NULL)
	{
		free(queue);
		return NULL;
	}
	queue->size = 0;
	queue->capacity = MAX;
	return queue;
}
//���	----------β��
void push_SeqQueue(SeqQueue queue, void* data)
{
	if (queue == NULL || data == NULL) return;
	QueueRecord* tmp = queue;
	if (tmp->size == tmp->capacity)
	{
		Person* p = realloc(tmp->arr, sizeof(Person) * tmp->capacity * 2);
		if (p == NULL) return;
		tmp->arr = p;
		tmp->capacity *= 2;
	}
	Person* pp = data;
	tmp->arr[tmp->size] = *pp;
	tmp->size++;
}

//���� ----------- ͷɾ
void pop_SeqQueue(SeqQueue queue)
{
	if (queue == NULL) return;
	QueueRecord* tmp = queue;
	if (tmp->size == 0) return;
	for (int i = 0; i < tmp->size - 1; i++)
	{
		tmp->arr[i].age = tmp->arr[i + 1].age;
		strcpy(tmp->arr[i].name, tmp->arr[i + 1].name);
	}
	tmp->size--;
}
//���ض�ͷ
void* front_SeqQueue(SeqQueue queue)
{
	if (!queue) return NULL;
	QueueRecord* tmp = queue;
	if (tmp->size == 0) return NULL;
	return &(tmp->arr[0]);
}
//���ض�β
void* back_SeqQueue(SeqQueue queue)
{
	if (!queue) return NULL;
	QueueRecord* tmp = queue;
	if (tmp->size == 0) return NULL;
	return &(tmp->arr[tmp->size - 1]);
}
//���ض��д�С
int size_SeqQueue(SeqQueue queue)
{
	if (!queue) return -1;
	QueueRecord* tmp = queue;
	return tmp->size;
}
//�ж϶����Ƿ�Ϊ��
int IsEmpty(SeqQueue queue)
{
	if (!queue) return -1;
	QueueRecord* tmp = queue;
	return tmp->size == 0;
}
//���ٶ���
void destroy_SeqQueue(SeqQueue queue)
{
	if (!queue) return;
	QueueRecord* tmp = queue;
	free(tmp->arr);
	free(tmp);
}