#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#include<string.h>
//int  main()
//{
//	char password[20] = { 0 };
//	int i = 0;
//	printf("����������:\n");
//	for (i = 0; i < 3; i++)
//	{
//	
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("��¼�ɹ�\n");
//			break;
//		}
//		else if (i < 2)
//		{
//			printf("�����������������\n");
//		}
//
//	}
//	if (i == 3)
//		printf("���ζ�����\n");
//	return 0;
//}

//int Is_Year(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		return 1;
//	else return 0;
//}
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	int ret = Is_Year(year);
//	if (ret) printf("%d������\n", year);
//	else printf("%d��������\n", year);
//	return 0;
//}
//void swap(int* p1, int* p2)
//{
//	int tmp = 0;
//	tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("����ǰ:a = %d,b = %d\n", a, b);
//	swap(&a, &b);
//	printf("������:a = %d,b = %d\n", a, b);
//	return 0;
//}
void Print(int n)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%-4d", j, i, j * i);
		}
		printf("\n");
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	Print(n);
	return 0;
}