#include "Add.h"



void test1()
{
	LinkNode* L1 = CreatLinkNode();
	LinkNode* L2 = CreatLinkNode();
	LinkNode* sum_Node = Add(L1, L2);
	double x;
	printf(" ‰»Î≤Œ ˝x£∫\n");
	scanf("%lf", &x);
	double sum = Sum(sum_Node, x);
	printf("%lf\n", sum);
	Destory(L1);
	Destory(L2);
	Destory(sum_Node);

}
int main()
{
	//test1();
	double sum = 2 * pow(1.4, 9) + 9 * pow(1.4, 2) + 5 * 1.4 + 2.1;
	printf("%lf", sum);
	return 0;
}