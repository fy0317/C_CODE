#include"stack.h"

void test1()
{
	Stack S = CreatStack();
	Push(1, S);
	Push(2, S);
	Push(3, S);
	Push(4, S);
	while (!IsEmpty(S))
	{
		printf("%d ", Top(S));
		Pop(S);
	}
}
int main()
{
	test1();
	return 0;
}