#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//int main()
//{
//	int random = 0;
//	srand((unsigned int)time(NULL));     //��srand��ʼ������
//	for (int i = 0; i < 10; i++)
//	{
//		random = rand();		//��rand����һ�������
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
	//srand((unsigned int )time(NULL));     //��srand��ʼ������
	for (int i = 0; i < 10; i++)
	{
		srand((unsigned int)time(NULL));     //��srand��ʼ������
		random = rand();		//��rand����һ�������
		printf("%d\n", random);
	}
	return 0;
}


