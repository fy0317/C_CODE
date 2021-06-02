
#include"stack.h"
void test1()
{
	struct StackRecord* S = CreatStack(5);
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	Push(S, 4);
	Push(S, 5);
	Push(S, 6);
	while (!IsEmpty(S))
	{
		printf("%d ", TopAndPop(S));
	}
	DisposeStack(S);
}
int main()
{
	test1();
	return 0;
}