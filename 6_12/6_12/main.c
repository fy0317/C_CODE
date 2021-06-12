#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int my_strlen(const char* str)
{
	if (str == NULL)return -1;
	const char* tmp = str;
	while (*str++)
		;
	return str - tmp - 1;
}
char* my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	if (dest == NULL || src == NULL)return NULL;
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int my_strcmp(const char* str1, const char* str2)
{
	if (str1 == NULL || str2 == NULL)
		return;
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 > *str2)
		return 1;
	else if 
		(*str1 < *str2) return -1;
	else 
		return 0;
}
char* my_strcat(char* dest, const char* src)
{
	if (dest == NULL || src == NULL) return NULL;
	char* ret = dest;
	while (*dest)
		dest++;
	while (*dest++ = *src++)
		;
	return ret;
}

//BFËã·¨
char* my_strstr_BF(const char* str1, const char* str2)
{
	if (str1 == NULL || str2 == NULL)return NULL;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len2 == 0)return NULL;
	if (len2 > len1)return NULL;
	const char* tmp1 = str1;
	const char* tmp2 = str2;
	while (*str1 && *str2)
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
		{
			str1 = ++tmp1;
			str2 = tmp2;
		}
	}
	return *str2 == 0 ? tmp1 : NULL;
}

void GetNext(const char* pattern, int* next)
{
	next[0] = -1;
	int len = strlen(pattern);
	int i = 0;
	int k = -1;
	while (i < len - 1)
	{
		if (k < 0 || pattern[k] == pattern[i])
		{
			next[++i] = ++k;
		}
		else k = next[k];
	}
}

char* my_strstr_KMP(const char* text, const char* pattern)
{
	if (text == NULL || pattern == NULL)return NULL;
	int Tlen = strlen(text);
	int Plen = strlen(pattern);
	if (Plen == 0)return NULL;
	if (Tlen < Plen)return NULL;
	int* next = malloc(sizeof(int) * Plen);
	GetNext(pattern,next);
	int ti = 0, pi = 0;
	while (ti < Tlen && pi < Plen)
	{
		if (pi < 0 || text[ti] == pattern[pi])
		{
			pi++;
			ti++;
		}
		else pi = next[pi];
	}
	free(next);
	return pi == Plen ? text + (ti - pi) : NULL;
}


int main()
{
	char arr1[30] = "abababd";
	char arr2[] = "abc";
	char arr3[] = "abd";
	printf("%s\n", my_strstr_BF(arr1, arr2));
	printf("%s\n", my_strstr_KMP(arr1, arr2));
	printf("%s\n", my_strstr_BF(arr1, arr3));
	printf("%s\n", my_strstr_KMP(arr1, arr3));
	return 0;
}

