#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
typedef struct Person
{
	char name[20];
	int age;
}Person;
void test()
{
	Person p1 = { "�ŷ�",30 };
	Person p2 = { "����",20 };
	Person p3 = { "����",33 };
	Person p4 = { "�����",40 };
	Person p5 = { "��",23 };
	Person p6 = { "����",31 };

	Stack* My_stack = InitStack();
	PushStack(My_stack, &p1);
	PushStack(My_stack, &p2);
	PushStack(My_stack, &p3);
	PushStack(My_stack, &p4);
	PushStack(My_stack, &p5);
	PushStack(My_stack, &p6);
	printf("ջ�Ĵ�СΪ:%d\n", SizeStack(My_stack));
	while (Isempty(My_stack) == 0)
	{
		Person* top = TopStack(My_stack);
		PopStack(My_stack);
		printf("����:%s  ���� :%d\n", top->name, top->age);
	}
	printf("ջ�Ĵ�СΪ:%d\n", SizeStack(My_stack));


}
int main()
{
	test();
	return 0;
}