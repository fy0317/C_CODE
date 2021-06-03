#include"LinkQueue.h"
//��ʼ������
LinkQueue init_LinkQueue()
{
	LQueue* queue = malloc(sizeof(LQueue));
	if (queue == NULL)return NULL;
	//���������ݳ�ʼ��
	queue->pHeader.next = NULL;
	queue->size = 0;
	queue->pTail = &queue->pHeader;
	return queue;
}
//���-------------β��
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
//����--------------ͷɾ
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
//���ض�ͷ
void* front_LinkQueue(LinkQueue queue)
{
	if (queue == NULL) return NULL;
	LQueue* tmp = queue;
	if (tmp->size == 0) return NULL;
	return tmp->pHeader.next;
}
//���ض�β
void* back_LinkQueue(LinkQueue queue)
{
	if (queue == NULL) return NULL;
	LQueue* tmp = queue;
	if (tmp->size == 0) return NULL;
	return tmp->pTail;
}
//���ض��д�С
int size_LinkQueue(LinkQueue queue)
{
	if (queue == NULL) return -1;
	LQueue* tmp = queue;
	return tmp->size;
}
//�ж��Ƿ�Ϊ��
int isEmpty(LinkQueue queue)
{
	if (queue == NULL) return -1;
	LQueue* tmp = queue;
	return tmp->size == 0;
}
//���ٶ���
void destory_LinkQueue(LinkQueue queue)
{
	if (!queue) return;
	free(queue); 
}