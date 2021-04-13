#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	FILE* p;
	int arr[100] = { 0 };
	p = fopen("test.txt", "w");
	if (p == NULL)
	{
		printf("%s", strerror(errno));
	}
	else
	{
		//printf("%c", fgetc(p));
		//puts(", p);
		//fgets(arr, 50, p);
		//printf("%s", arr);
		fputs("hello world!\n", p);
		fclose(p);
		p = NULL;

	}
	return 0;
}