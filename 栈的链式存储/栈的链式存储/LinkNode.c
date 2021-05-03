#include"LinkNode.h"

//初始化栈
LinkStack Init_Linkstack()
{
	Lstack* myStack = malloc(sizeof(Lstack));
	if (myStack == NULL) return NULL;
	myStack->phead.next = NULL;
	myStack->size = 0;
	return myStack;
}

//入栈
void Push_Linkstack(LinkStack stack, void* data)
{
	if (stack == NULL || data == NULL) return;
	Lstack* my_stack = stack;

	//取出用户前4个字节
	LinkNode* my_node = data;		//用户前4个字节用来存放下一个节点的地址

	//建立节点之间的联系
	my_node->next = my_stack->phead.next;
	my_stack->phead.next = my_node;

	my_stack->size++;	//更新栈的大小
}
//出栈
void Pop_Linkstack(LinkStack stack)
{
	if (stack == NULL) return;
	Lstack* my_stack = stack;
	//头删
	if (my_stack->size == 0) return;
	my_stack->phead.next = my_stack->phead.next->next;
	my_stack->size--;
}
//返回栈顶
void* top_Linkstack(LinkStack stack)
{
	if (stack == NULL) return NULL;
	Lstack* my_stack = stack;
	if (my_stack->size == 0) return NULL;
	return my_stack->phead.next;

}
//返回栈的大小
int Size_Linkstack(LinkStack stack)
{
	if (stack == NULL) return -1;
	Lstack* my_stack = stack;
	return my_stack->size;
}
//判断栈是否为空
int Isempty(LinkStack stack)
{
	if (stack == NULL) return -1;
	Lstack* my_stack = stack;
	if (my_stack->size == 0) return 1;
	return 0;
}
//销毁栈
void Destory(LinkStack stack)
{
	if (stack == NULL) return;
	free(stack);
	stack = NULL;
}