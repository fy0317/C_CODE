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
	int n_columns;		//����colunms���ļ�����֮����Ҫ����
	int columns[MAX_COLS];		//ÿ��Ԫ���ж�����
	char input[MAX_INPUT];		//���������ַ���
	char output[MAX_INPUT];		//������ַ���

	n_columns = read_column_numbers(columns, MAX_COLS);		//��ȡ�б��
	while (gets(input) != NULL)			//�����ַ���
	{
		printf("Original input : %s\n", input);
		rearrange(output, input, n_columns, columns);		//�ַ�����������
		printf("Rearranged line: %s\n", output);
	}
	return 0;
}

int read_column_numbers(int columns[], int max)
{
	int num = 0;
	int ch;
	while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] > 0)	//��¼�б��
	{
		num++;
	}
	if (num % 2 != 0) {
		puts("Last column number is not paired.");		//ÿ����Ϊ1�ԣ�numΪ�����������һ��û�гɶ�
		return (EXIT_FAILURE);
	}
	while ((ch = getchar()) != EOF && ch != '\n')		//����������е�\n
		;
	return num;
}
/*
		��input[]�е��ַ����������У���ŵ�output[]��
		���й���
		��colunms[]��ÿ����Ԫ����ԣ������0��Ԫ�غ͵�һ��Ԫ����ԣ��ڶ���Ԫ�غ͵�����Ԫ�����
		��input[]�дӵ�columns[i]��Ԫ���𣬿���columns[i + 1] - columns[i] + 1	��Ԫ�ص�output[]��
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
