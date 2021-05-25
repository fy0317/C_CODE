#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COLS 20
#define MAX_INPUT 1000
int read_column_numbers(int columns[], int max);
void rearrange(char* output, char const* input, int n_columns, int const colunms[]);

int main()
{
	int n_columns;		//数组colunms中哪几个列之间需要处理
	int columns[MAX_COLS];		//每个元素有多少列
	char input[MAX_INPUT];		//存放输入的字符串
	char output[MAX_INPUT];		//输出的字符串

	n_columns = read_column_numbers(columns, MAX_COLS);		//获取列标号
	while (gets(input) != NULL)			//输入字符串
	{
		printf("Original input : %s\n", input);
		rearrange(output, input, n_columns, columns);		//字符串重新排列
		printf("Rearranged line: %s\n", output);
	}
	return 0;
}

int read_column_numbers(int columns[], int max)
{
	int num = 0;
	int ch;
	while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] > 0)	//记录列标号
	{
		num++;
	}
	if (num % 2 != 0) {
		puts("Last column number is not paired.");		//每两个为1对，num为基数，则最后一个没有成对
		return (EXIT_FAILURE);
	}
	while ((ch = getchar()) != EOF && ch != '\n')		//清除缓存区中的\n
		;
	return num;
}
/*
		将input[]中的字符串重新排列，存放到output[]中
		排列规则：
		将colunms[]中每两个元素配对，例如第0个元素和第一个元素配对，第二个元素和第三个元素配对
		将input[]中从第columns[i]个元素起，拷贝columns[i + 1] - columns[i] + 1	个元素到output[]中
*/
void rearrange(char* output, char const* input, int n_columns, int const colunms[])
{
	int col;
	int output_col;
	int len;
	len = strlen(input);
	output_col = 0;
	for (col = 0; col < n_columns; col += 2)
	{
		int nchars = colunms[col + 1] - colunms[col] + 1;

		if (colunms[col] >= len || output_col == MAX_INPUT - 1)
			break;

		if (output_col + nchars > MAX_INPUT - 1)
			nchars = MAX_INPUT - output_col - 1;
		strncpy(output + output_col, input + colunms[col], nchars);
		output_col += nchars;
	}
	output[output_col] = '\0';
}
