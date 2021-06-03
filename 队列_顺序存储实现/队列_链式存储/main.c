#include"LinkQueue.h"

void test1()
{
	LinkQueue queue = init_LinkQueue();
	Person p1 = { NULL,"张三", 20 };
	Person p2 = { NULL,"李四", 28 };
	Person p3 = { NULL,"王五", 18 };
	Person p4 = { NULL,"李化", 29 };
	Person p5 = { NULL,"赵华", 21 };
	push_LinkQueue(queue, &p1);
	push_LinkQueue(queue, &p2);
	push_LinkQueue(queue, &p3);
	push_LinkQueue(queue, &p4);
	push_LinkQueue(queue, &p5);
	while (!isEmpty(queue))
	{
		Person* pfront = front_LinkQueue(queue);
		Person* pback = back_LinkQueue(queue);
		printf("队头：%s  %d\n", pfront->name, pfront->age);
		printf("队尾：%s  %d\n", pback->name, pback->age);
		pop_LinkQueue(queue);
	}
	destory_LinkQueue(queue);
}
int main()
{
	test1();
	return 0;
}