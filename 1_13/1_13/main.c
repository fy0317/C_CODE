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
//#define MAXWORD 11			//单词的最大长度
//#define IN 1				//在单词内
//#define OUT 0				//在单词外
//int main()
//{
//	int c, i, nc, state;
//	int len;				//当前单词长度
//	int maxvalue;
//	int ovflow;				//超过最大单词长度的个数
//	int wl[MAXWORD] = { 0 };	//存放单词个数
//	state = OUT;
//	nc = 0;					//单词中字符的个数
//	ovflow = 0;
//
//	//计算单词长度的个数
//
//	while ((c = getchar()) != EOF)
//	{
//		if (c == ' ' || c == '\n' || c == '\t')		//当字符c为这三个字符时，说明当前状态在单词外
//		{
//			state = OUT;
//			if (nc > 0)								//如果单词长度大于0并且没有超过长度限制，则长度为nc的单词数加1，用wl[nc]表示单词长度为nc的单词个数
//				if (nc < MAXWORD)
//					++wl[nc];
//				else ovflow++;						//超出单词长度，则oveflow加1
//
//			nc = 0;									//当前在单词外面，因此加单词长度置为0
//		}
//		else if (state == OUT)						//如果c不为 ' '  '\n'  '\t'，并且state == OUT，说明刚刚进入一个新的单词
//		{
//			state = IN;								//state置为IN，表示当前正处于单词内
//			nc = 1;									//单词长度至少为1，置为1
//		}
//		else nc++;									//c不为 ' '  '\n'  '\t'，并且state == IN ，表示当前还处于单词内，长度加1
//
//	}
//	
//	//输出
//
//	maxvalue = 0;
//	for (i = 1; i < MAXWORD; i++)					//统计出最大的单词长度
//		if (wl[i] > maxvalue)
//			maxvalue = wl[i];
//
//	for (i = 1; i < MAXWORD; i++)					
//	{
//		printf("%5d - %5d :", i, wl[i]);			//单词长度为i的单词有wl[i]个
//		if (wl[i] > 0)								//当单词长度不为0时，输出       wl[i] * MAXHISTT / maxvalue 个  *，如果这个数小于0，则至少输出1个*
//		{
//			if ((len = wl[i] * MAXHISTT / maxvalue) <= 0)
//				len = 1;
//		}
//		else len = 0;								//如果单词长度为i的单词0个，则不输出*
//		while (len > 0)								//输出len个*
//		{
//			putchar('*');
//			len--;
//		}
//		putchar('\n');								//一行结束，换行
//	}
//
//	if (ovflow > 0)									//输出超出范围的单词个数	
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
