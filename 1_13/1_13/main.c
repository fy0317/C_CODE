#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	char arr[100]  = { 0 };
//	gets(arr);
//	int i = 0;
//	int inword = 0;
//	int line = 1;
//	int j = 0;
//	while (arr[i] != '\0')
//	{
//		if ((inword == 0) && arr[i] != ' ')
//		{
//			while (arr[i] != ' ' && arr[i] != '\0')
//			{
//				putchar(arr[i]);
//				i++;
//			}
//			printf("				");
//			for (j = 0; j < line; j++)
//			{
//				putchar('*');
//			}
//			line++;
//			printf("\n");
//			inword = 1;
//
//		}
//		else if ((inword == 1) && arr[i] == ' ')
//			inword = 0, i++;
//
//	}
//	return 0;
//}

//#define MAXHISTT 15
//#define MAXWORD 11			//���ʵ���󳤶�
//#define IN 1				//�ڵ�����
//#define OUT 0				//�ڵ�����
//int main()
//{
//	int c, i, nc, state;
//	int len;				//��ǰ���ʳ���
//	int maxvalue;
//	int ovflow;				//������󵥴ʳ��ȵĸ���
//	int wl[MAXWORD] = { 0 };	//��ŵ��ʸ���
//	state = OUT;
//	nc = 0;					//�������ַ��ĸ���
//	ovflow = 0;
//
//	//���㵥�ʳ��ȵĸ���
//
//	while ((c = getchar()) != EOF)
//	{
//		if (c == ' ' || c == '\n' || c == '\t')		//���ַ�cΪ�������ַ�ʱ��˵����ǰ״̬�ڵ�����
//		{
//			state = OUT;
//			if (nc > 0)								//������ʳ��ȴ���0����û�г����������ƣ��򳤶�Ϊnc�ĵ�������1����wl[nc]��ʾ���ʳ���Ϊnc�ĵ��ʸ���
//				if (nc < MAXWORD)
//					++wl[nc];
//				else ovflow++;						//�������ʳ��ȣ���oveflow��1
//
//			nc = 0;									//��ǰ�ڵ������棬��˼ӵ��ʳ�����Ϊ0
//		}
//		else if (state == OUT)						//���c��Ϊ ' '  '\n'  '\t'������state == OUT��˵���ոս���һ���µĵ���
//		{
//			state = IN;								//state��ΪIN����ʾ��ǰ�����ڵ�����
//			nc = 1;									//���ʳ�������Ϊ1����Ϊ1
//		}
//		else nc++;									//c��Ϊ ' '  '\n'  '\t'������state == IN ����ʾ��ǰ�����ڵ����ڣ����ȼ�1
//
//	}
//	
//	//���
//
//	maxvalue = 0;
//	for (i = 1; i < MAXWORD; i++)					//ͳ�Ƴ����ĵ��ʳ���
//		if (wl[i] > maxvalue)
//			maxvalue = wl[i];
//
//	for (i = 1; i < MAXWORD; i++)					
//	{
//		printf("%5d - %5d :", i, wl[i]);			//���ʳ���Ϊi�ĵ�����wl[i]��
//		if (wl[i] > 0)								//�����ʳ��Ȳ�Ϊ0ʱ�����       wl[i] * MAXHISTT / maxvalue ��  *����������С��0�����������1��*
//		{
//			if ((len = wl[i] * MAXHISTT / maxvalue) <= 0)
//				len = 1;
//		}
//		else len = 0;								//������ʳ���Ϊi�ĵ���0���������*
//		while (len > 0)								//���len��*
//		{
//			putchar('*');
//			len--;
//		}
//		putchar('\n');								//һ�н���������
//	}
//
//	if (ovflow > 0)									//���������Χ�ĵ��ʸ���	
//		printf("There are %d words >= %d\n", ovflow, MAXWORD);
//	return 0;
//}


#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0

int main()
{
	int c, i, j, nc, state;
	int maxvalue;
	int ovflow;
	int wl[MAXWORD] = { 0 };
	state = OUT;
	nc = 0;
	ovflow = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
			if (nc > 0)
				if (nc < MAXWORD)
					wl[nc]++;
				else ovflow++;
			nc = 0;
		}
		else if (state == OUT)
		{
			state = IN;
			nc = 1;
		}
		else nc++;
	}

	maxvalue = 0;
	for (i = 0; i < MAXWORD; i++)
	{
		if (wl[i] > maxvalue)
			maxvalue = wl[i];
	}

	for (i = MAXHIST; i > 0; i--)
	{
		for (j = 1; j < MAXWORD; j++)
			if (wl[j] * MAXHIST / maxvalue >= i)
				printf("*");
			else printf("   ");
		putchar('\n');
	}
	for (i = 1; i < MAXWORD; i++)
		printf("%4d ", i);
	putchar('\n');
	for (i = 1; i < MAXWORD; i++)
		printf("%4d ", wl[i]);
	putchar('\n');
	if (ovflow > 0)
		printf("There are %d words >= %d\n", ovflow, MAXWORD);
	return 0;
}
