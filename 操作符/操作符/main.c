#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//struct book {
//	char name[20];
//	char id[20];
//	int price;
//};
//int main()
//{
//	struct book b = { "CÓïÑÔ", "I21312312", 20 };
//	struct book* p = &b;
//	printf("%s\t%s\t%d\n", b.name, b.id, b.price);
//	printf("%s\t%s\t%d\n", p->name, p->id, p->price);
//	printf("%s\t%s\t%d\n", (*p).name, (*p).id, (*p).price);
//	return 0;
//}

//ÕûĞÍÌáÉı
//int main()
//{
//	char a = 3;
//	char b = 127;
//	char c = a + b;
//	printf("%d %d", c, a + b);
//	return 0;
//}

//-------------------------
int fun()
{
	static cnt = 1;
	return ++cnt;
}
int main()
{
	int a = fun() - fun() * fun();
	printf("%d", a);
	return 0;
}