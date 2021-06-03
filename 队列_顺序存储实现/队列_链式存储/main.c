#include"LinkQueue.h"

void test1()
{
	LinkQueue queue = init_LinkQueue();
	Person p1 = { NULL,"����", 20 };
	Person p2 = { NULL,"����", 28 };
	Person p3 = { NULL,"����", 18 };
	Person p4 = { NULL,"�", 29 };
	Person p5 = { NULL,"�Ի�", 21 };
	push_LinkQueue(queue, &p1);
	push_LinkQueue(queue, &p2);
	push_LinkQueue(queue, &p3);
	push_LinkQueue(queue, &p4);
	push_LinkQueue(queue, &p5);
	while (!isEmpty(queue))
	{
		Person* pfront = front_LinkQueue(queue);
		Person* pback = back_LinkQueue(queue);
		printf("��ͷ��%s  %d\n", pfront->name, pfront->age);
		printf("��β��%s  %d\n", pback->name, pback->age);
		pop_LinkQueue(queue);
	}
	destory_LinkQueue(queue);
}
int main()
{
	test1();
	return 0;
}