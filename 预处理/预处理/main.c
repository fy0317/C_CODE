#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#define PRINT(X) printf("The value of "#X" is %d\n",X)
//void print(int a)
//{
//	printf("The value of a is %d\n", a);
//}
//int main()
//{
//	int a = 10, b = 20;
//	print(a);
//	print(b);
//	PRINT(a);
//	PRINT(b);
//	return 0;
//}
//#define CAT(X,Y) X##Y
//int main()
//{
//	int Class101 = 2021;
//	printf("%d\n", CAT(Class, 101));
//	return 0;
//}
//#define MAX(X,Y) (X)>(Y)?(X):(Y)
//int max(int a,int  b)
//{
//	return a > b ? a : b;
//}
//int main()
//{
//	int a = 10, b = 11;
//	float c = 3.0f, d = 4.0f;
//	int ret = max(c, d);
//	printf("%d\n", ret);
//	ret = MAX(c, d);
//	printf("%d\n", ret);
//
//	return 0;
//}
//#include <stddef.h>
//#define OFFSETOF(struct_name , member_name)  (int)&(((struct_name*)0)->member_name)
//struct S {
//	char c;
//	int a;
//	char b;
//};
//int main()
//{
//	//struct S s;
//	printf("%d\n", OFFSETOF(struct S, c));
//	printf("%d\n", OFFSETOF(struct S, a));
//	printf("%d\n", OFFSETOF(struct S, b));
//
//	return 0;
//}
//#include<string.h>
//int main()
//{
//	unsigned char puc[4];
//	struct tagPIM
//	{
//		unsigned char ucPim1;
//		unsigned char ucData0 : 1;
//		unsigned char ucData1 : 2;
//		unsigned char ucData2 : 3;
//	}*pstPimData;
//	pstPimData = (struct tagPIM*)puc;
//	memset(puc, 0, 4);
//	pstPimData->ucPim1 = 2;
//	pstPimData->ucData0 = 3;
//	pstPimData->ucData1 = 4;
//	pstPimData->ucData2 = 5;
//	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//	return 0;
//
//}
//int main()
//{
//    int weight = 0;
//    int high = 0;
//    scanf("%d %d", &weight, &high);
//    float BIM = (float)weight /(high/100.0)/(high/100.0);
//    printf("%.2f", BIM);
//    return 0;
//}
enum A
{
	A=10,
	B,
	C,
	D
};
struct S
{
	int arr[A];
	int b;
};
int main()
{
	struct S s = { {1,2,3,4,5},1 };
	int i = 0;
	for (i = 0; i < A; i++)
	{
		printf("%d ",s.arr[i]);
	}
	printf("\n%d ", s.b);
	return 0;
}