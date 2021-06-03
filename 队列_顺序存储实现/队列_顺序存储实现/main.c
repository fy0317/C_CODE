#include"SeqQueue.h"


void test1()
{
	SeqQueue queue = Init_SeqQueue();
	Person p1 = { "����", 20 };
	Person p2 = { "����", 28 };
	Person p3 = { "����", 18 };
	Person p4 = { "�", 29 };
	Person p5 = { "�Ի�", 21 };
	push_SeqQueue(queue, &p1);
	push_SeqQueue(queue, &p2);
	push_SeqQueue(queue, &p3);
	push_SeqQueue(queue, &p4);
	push_SeqQueue(queue, &p5);
	while (!IsEmpty(queue))
	{
		Person* pfront = front_SeqQueue(queue);
		Person* pback = back_SeqQueue(queue);
		printf("��ͷ��%s  %d\n", pfront->name, pfront->age);
		printf("��β��%s  %d\n", pback->name, pback->age);
		pop_SeqQueue(queue);
	}
	destroy_SeqQueue(queue);
}
int main()
{
	test1();
	return 0;
}