#include"LinkNode.h"


void test3_4()
{

}
void test()
{
	LinkNode* L1 = CreatLinkNode();
	LinkNode* L2 = CreatLinkNode();
	LinkNode* L1_and_L2 = L1_And_L2(L1, L2);
	PrintLinkNode(L1);
	PrintLinkNode(L2);
	printf("L1 and L2 : \n");
	PrintLinkNode(L1_and_L2);
	Destory(L1_and_L2);
	LinkNode* L1_or_L2 = L1_Or_L2(L1, L2);
	printf("L1 or L2 : \n");
	PrintLinkNode(L1_or_L2);
	PrintLinkNode(L1);
	PrintLinkNode(L2);
	Destory(L1_or_L2);
	Destory(L1);
	Destory(L2);
}
int main()
{
	test();
	return 0;
}