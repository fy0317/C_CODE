#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//��ӡ����
//int main()
//{
//	int n = 0;		//����
//	scanf("%d", &n);
//	int i = 0;
//	//for (int i = 0; i <= n; i++)
//	//{
//	//	for (int j = 0; j < n - i; j++)
//	//		printf(" ");
//	//	for (int j = 0; j <= i; j++)
//	//		printf("* ");
//	//	printf("\n");
//	//}
//	//for (int i = 0; i < n; i++)
//	//{
//	//	for (int j = 0; j <= i; j++)
//	//		printf(" ");
//	//	for (int j = 0; j < n - i; j++)
//	//	{
//	//		printf("* ");
//	//	}
//	//	printf("\n");
//	//}
//	for (i = 0; i < (n + 1) / 2; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n / 2 - i; j++)
//		{
//			printf("  ");
//		}
//		for (j = 0; j < 2 * i + 1; j++)
//			printf("* ");
//		printf("\n\n");
//	}
//	for (i = 0; i < n / 2; i++)
//	{
//		int j = 0;
//		for (j = 0; j < i + 1; j++)
//			printf("  ");
//		for (j = 0; j < 2 * (n / 2 - 1 - i) + 1 ; j++)
//			printf("* ");
//		printf("\n\n");
//	}
//	return 0;
//}


// �����ַ���
//#include<string.h>
//void reverse(char* arr,int len)
//{
//	for (int i = 0; i < len / 2; i++)
//	{
//		char tmp = arr[i];
//		arr[i] = arr[len - i - 1];
//		arr[len - 1 - i] = tmp;
//	}
//}
//int main()
//{
//	int len = 0;
//	char arr[100] = { 0 };
//	//printf("�ַ�������\n");
//	//scanf("%d", &n);
//	//char* arr = (char*)malloc(sizeof(char) * (n + 1));
//	printf("�ַ�������\n");
//	gets(arr);
//	len = strlen(arr);
//	reverse(arr,len);
//	printf("%s", arr);
//	return 0;
//}

//����ˮ����
int main()
{
	int money = 0;
	scanf("%d", &money);
	int cnt = money;
	int empty = money;
	while (empty >1)
	{
		cnt += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("%dԪ���Ժ�%dƿ��ˮ\n", money, cnt);
	return 0;
}