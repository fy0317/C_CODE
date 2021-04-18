#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//void print(unsigned  int n)
//{
//	if (n < 10)
//		printf("%d", n);
//	else
//	{
//		printf("%d ", n % 10);
//		print(n / 10);
//	
//	}
//
//}
/*int my_strlen(char* p)
{
	if (*p != '\0')
		return  1 + my_strlen(p + 1);
	else return 0;

}
int main()
{
	char  arr[] = "adadad";
	int num = my_strlen(arr);
	printf("%d", num);
	return 0;
}	*/	

int  Fib(int  n)
{
	int  a = 1;
	int  b = 1;
	int i = 0;
	int c = 0;
	if (n <= 2)
		return  1;
	else
	{
		for (i = 3; i <= n; i++)
		{
			c = a + b;
			a = b;
			b = c;

		}
	}
	return c;
}

int  main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fib(n);
	printf("%d", ret);
	return 0;
}