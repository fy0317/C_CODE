#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void test(char s[])
{
	int i = 0;
	int in = 1;
	int new = 0;
	while (s[i])
	{
		if (s[i] == 32)
		{
			if (in == 0)
			{
				s[new++] = s[i];
				in = 1;
			}
		}
		else
		{
			s[new++] = s[i];
			in = 0;
		}
		i++;
	}
	if (s[new - 1] == 32) s[new - 1] = 0;
	else s[new] = 0;
}
int main()
{
	char s[30];
	gets(s);
	test(s);
	printf("¿Õ¸ñÉ¾³ýºó:%send", s);
	return 0;
}