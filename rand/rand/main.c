#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//int main()
//{
//	int random = 0;
//	srand((unsigned int)time(NULL));     //用srand初始化种子
//	for (int i = 0; i < 10; i++)
//	{
//		random = rand();		//用rand产生一个随机数
//		printf("%d\n", random);
//	}
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int random = 0;
	//srand((unsigned int )time(NULL));     //用srand初始化种子
	for (int i = 0; i < 10; i++)
	{
		srand((unsigned int)time(NULL));     //用srand初始化种子
		random = rand();		//用rand产生一个随机数
		printf("%d\n", random);
	}
	return 0;
}


