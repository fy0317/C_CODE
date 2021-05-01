#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
typedef struct Person
{
	char name[20];
	int age;
}Person;
void test()
{
	Person p1 = { "张飞",30 };
	Person p2 = { "赵云",20 };
	Person p3 = { "关羽",33 };
	Person p4 = { "诸葛亮",40 };
	Person p5 = { "马超",23 };
	Person p6 = { "黄忠",31 };

	Stack* My_stack = InitStack();
	PushStack(My_stack, &p1);
	PushStack(My_stack, &p2);
	PushStack(My_stack, &p3);
	PushStack(My_stack, &p4);
	PushStack(My_stack, &p5);
	PushStack(My_stack, &p6);
	printf("栈的大小为:%d\n", SizeStack(My_stack));
	while (Isempty(My_stack) == 0)
	{
		Person* top = TopStack(My_stack);
		PopStack(My_stack);
		printf("姓名:%s  年龄 :%d\n", top->name, top->age);
	}
	printf("栈的大小为:%d\n", SizeStack(My_stack));


}
int main()
{
	test();
	return 0;
}