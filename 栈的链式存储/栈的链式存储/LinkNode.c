#include"LinkNode.h"

//��ʼ��ջ
LinkStack Init_Linkstack()
{
	Lstack* myStack = malloc(sizeof(Lstack));
	if (myStack == NULL) return NULL;
	myStack->phead.next = NULL;
	myStack->size = 0;
	return myStack;
}

//��ջ
void Push_Linkstack(LinkStack stack, void* data)
{
	if (stack == NULL || data == NULL) return;
	Lstack* my_stack = stack;

	//ȡ���û�ǰ4���ֽ�
	LinkNode* my_node = data;		//�û�ǰ4���ֽ����������һ���ڵ�ĵ�ַ

	//�����ڵ�֮�����ϵ
	my_node->next = my_stack->phead.next;
	my_stack->phead.next = my_node;

	my_stack->size++;	//����ջ�Ĵ�С
}
//��ջ
void Pop_Linkstack(LinkStack stack)
{
	if (stack == NULL) return;
	Lstack* my_stack = stack;
	//ͷɾ
	if (my_stack->size == 0) return;
	my_stack->phead.next = my_stack->phead.next->next;
	my_stack->size--;
}
//����ջ��
void* top_Linkstack(LinkStack stack)
{
	if (stack == NULL) return NULL;
	Lstack* my_stack = stack;
	if (my_stack->size == 0) return NULL;
	return my_stack->phead.next;

}
//����ջ�Ĵ�С
int Size_Linkstack(LinkStack stack)
{
	if (stack == NULL) return -1;
	Lstack* my_stack = stack;
	return my_stack->size;
}
//�ж�ջ�Ƿ�Ϊ��
int Isempty(LinkStack stack)
{
	if (stack == NULL) return -1;
	Lstack* my_stack = stack;
	if (my_stack->size == 0) return 1;
	return 0;
}
//����ջ
void Destory(LinkStack stack)
{
	if (stack == NULL) return;
	free(stack);
	stack = NULL;
}