#include"SeqQueue.h"

//初始化队列
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
//入队	----------尾插
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

//出队 ----------- 头删
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
//返回队头
void* front_SeqQueue(SeqQueue queue)
{
	if (!queue) return NULL;
	QueueRecord* tmp = queue;
	if (tmp->size == 0) return NULL;
	return &(tmp->arr[0]);
}
//返回队尾
void* back_SeqQueue(SeqQueue queue)
{
	if (!queue) return NULL;
	QueueRecord* tmp = queue;
	if (tmp->size == 0) return NULL;
	return &(tmp->arr[tmp->size - 1]);
}
//返回队列大小
int size_SeqQueue(SeqQueue queue)
{
	if (!queue) return -1;
	QueueRecord* tmp = queue;
	return tmp->size;
}
//判断队列是否为空
int IsEmpty(SeqQueue queue)
{
	if (!queue) return -1;
	QueueRecord* tmp = queue;
	return tmp->size == 0;
}
//销毁队列
void destroy_SeqQueue(SeqQueue queue)
{
	if (!queue) return;
	QueueRecord* tmp = queue;
	free(tmp->arr);
	free(tmp);
}