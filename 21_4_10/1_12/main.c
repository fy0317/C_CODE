#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//enum state {
//	OUT,
//	IN
//}s;
//int main()
//{
//	int c;
//	s =OUT;
//	while ((c=getchar())!=EOF)
//	{
//		if (c == ' ' || c == '\n' || c == '\t')
//		{
//			if (s == IN)
//			{
//				putchar('\n');
//				s = OUT;
//			}
//		}
//		else{
//			putchar(c);
//			s = IN;
//		}	
//	}
//	return 0;
//}
//int main()
//{
//	int ndigit[10] = { 0 };
//	int nwhite = 0, nother = 0;
//	int c = 0,i=0;
//	while ((c = getchar()) != EOF)
//	{
//		if (c == ' ' || c == '\n' || c == '\t')
//			nwhite++;
//		else if (c >= '0' && c <= '9')
//			ndigit[c - '0']++;
//		else nother++;
//	}
//	printf("nwhite=%d  nother=%d\n", nwhite, nother);
//	printf("digit: 0   1   2   3   4   5   6   7   8   9\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%3d", ndigit[i]);
//	}
//	return 0;
//}

//
//
//************************************


//              1_13


//***********************************

//#define MAXHIST 15   //直方图最大的长度
//#define MAXWORD 11   //单词最大的长度
//#define IN 1
//#define OUT 0
//int main()
//{
//	int c, i, nc, state;
//	int len;
//	int maxvalue;  //计数器的最大值
//	int ovflow;  //超出范围的单词数目
//	int wl[MAXWORD] = {0};    //单词长度计数器
//	state = OUT;
//	nc = 0;   //单词的长度
//	ovflow = 0;
//	while ((c=getchar())!=EOF)
//	{
//		if (c == ' ' || c == '\t' || c == '\n')
//		{
//			state = OUT;
//			if (nc > 0)
//				if (nc < MAXWORD)
//					++wl[nc];
//				else ++ovflow;  //nc>=MAXWORD
//			nc = 0;
//		}
//		else if (state == OUT)
//		{
//			state = IN;
//			nc = 1;   //开始一个新的单词
//		}
//		else nc++;
//	}
//	maxvalue = 0;
//	for (i = 1; i < MAXWORD; i++)
//		if (wl[i] > maxvalue)
//			maxvalue = wl[i];  //单词最长的长度
//	for (i = 1; i < MAXWORD; i++)
//	{
//		printf("%5d - %5d :", i, wl[i]);
//		if (wl[i] > 0)
//		{
//			if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
//				len = 1;
//		}
//		else len = 0;
//		while (len>0)
//		{
//			putchar('*');
//			len--;
//		}
//		putchar('\n');
//
//	}
//	if (ovflow > 0)
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
	int wl[MAXWORD];
	state = OUT;
	nc = 0;
	int ovflow = 0;
	for (i = 0; i < MAXWORD; i++)
		wl[i] = 0;
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
	for (i = 1; i < MAXWORD; i++)
		if (wl[i] > maxvalue)
			maxvalue = wl[i];
	for (i = MAXHIST; i > 0; i--)
	{
		for (j = 1; j < MAXWORD; j++)
			if (wl[j] * MAXHIST / maxvalue >= 1)
				printf(" * ");
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