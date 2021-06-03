#include"LinkQueue.h"
//初始化队列
LinkQueue init_LinkQueue()
{
	LQueue* queue = malloc(sizeof(LQueue));
	if (queue == NULL)return NULL;
	//给队列数据初始化
	queue->pHeader.next = NULL;
	queue->size = 0;
	queue->pTail = &queue->pHeader;
	return queue;
}
//入队-------------尾插
void push_LinkQueue(LinkQueue queue, void* data)
{
	if (queue == NULL || data == NULL) return;
	LQueue* tmp = queue;
	LinkNode* my_data = data;
	tmp->pTail->next = my_data;
	my_data->next = NULL;
	tmp->pTail = my_data;
	tmp->size++;
}
//出队--------------头删
void pop_LinkQueue(LinkQueue queue)
{
	if (queue == NULL) return;
	LQueue* tmp = queue;
	if (tmp->size == 0) return;
	tmp->pHeader.next = tmp->pHeader.next->next;
	tmp->size--;
	if (tmp->size == 0)
		tmp->pTail = &tmp->pHeader;
}
//返回队头
void* front_LinkQueue(LinkQueue queue)
{
	if (queue == NULL) return NULL;
	LQueue* tmp = queue;
	if (tmp->size == 0) return NULL;
	return tmp->pHeader.next;
}
//返回队尾
void* back_LinkQueue(LinkQueue queue)
{
	if (queue == NULL) return NULL;
	LQueue* tmp = queue;
	if (tmp->size == 0) return NULL;
	return tmp->pTail;
}
//返回队列大小
int size_LinkQueue(LinkQueue queue)
{
	if (queue == NULL) return -1;
	LQueue* tmp = queue;
	return tmp->size;
}
//判断是否为空
int isEmpty(LinkQueue queue)
{
	if (queue == NULL) return -1;
	LQueue* tmp = queue;
	return tmp->size == 0;
}
//销毁队列
void destory_LinkQueue(LinkQueue queue)
{
	if (!queue) return;
	free(queue); 
}