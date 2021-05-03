#include"LinkNode.h"
typedef struct Person
{
	int* a;
	char name[64];
	int age;
}Person;
void test()
{
	Person p1 = { NULL,"aaa",11 };
	Person p2 = { NULL,"bbb",22 };
	Person p3 = { NULL,"ccc",33 };
	Person p4 = { NULL,"ddd",44 };
	Person p5 = { NULL,"eee",55 };

	LinkStack myStack = Init_Linkstack();	//��ʼ��ջ
	//��ջ
	Push_Linkstack(myStack, &p1);
	Push_Linkstack(myStack, &p2);
	Push_Linkstack(myStack, &p3);
	Push_Linkstack(myStack, &p4);
	Push_Linkstack(myStack, &p5);
	printf("ջ�Ĵ�СΪ:%d\n", Size_Linkstack(myStack));
	while (Isempty(myStack) == 0)
	{
		Person* pTop = top_Linkstack(myStack);
		printf("����:%s   ����:%d\n", pTop->name, pTop->age);

		Pop_Linkstack(myStack);
	}
	printf("ջ�Ĵ�СΪ:%d\n", Size_Linkstack(myStack));
	Destory(myStack);

}
int main()
{
	test();
	return 0;
}