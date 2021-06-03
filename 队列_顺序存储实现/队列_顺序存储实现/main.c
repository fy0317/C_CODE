#include"SeqQueue.h"


void test1()
{
	SeqQueue queue = Init_SeqQueue();
	Person p1 = { "张三", 20 };
	Person p2 = { "李四", 28 };
	Person p3 = { "王五", 18 };
	Person p4 = { "李化", 29 };
	Person p5 = { "赵华", 21 };
	push_SeqQueue(queue, &p1);
	push_SeqQueue(queue, &p2);
	push_SeqQueue(queue, &p3);
	push_SeqQueue(queue, &p4);
	push_SeqQueue(queue, &p5);
	while (!IsEmpty(queue))
	{
		Person* pfront = front_SeqQueue(queue);
		Person* pback = back_SeqQueue(queue);
		printf("队头：%s  %d\n", pfront->name, pfront->age);
		printf("队尾：%s  %d\n", pback->name, pback->age);
		pop_SeqQueue(queue);
	}
	destroy_SeqQueue(queue);
}
int main()
{
	test1();
	return 0;
}