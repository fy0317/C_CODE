#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stddef.h>

struct teacher
{
	char a;
	int b;
	int arr[10];
};
//struct teacher {
//	int a;
//	char b;
//
//};
int main()
{
	struct teacher t1 = { 1,10,0 };
	printf("%d\n", sizeof(struct teacher));
	printf("%d\n", offsetof(struct teacher, b));
	printf("%d\n", (int)&(t1.b) - (int)&(t1));
	printf("b的值为:%d\n", t1.b);
	printf("b的值为:%d\n", * ((char*)&t1 + offsetof(struct teacher, b)) );
	return 0;
}