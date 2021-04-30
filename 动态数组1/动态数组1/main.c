#define _CRT_SECURE_NO_WARNINGS
#include"Dynamic.h"

typedef struct Person
{
	char name[20];
	int age;
}Person;
void PrintPerson(void* p)
{
	if (p == NULL) return;
	Person* p1 = (Person*)p;
	printf("ĞÕÃû:%s  ÄêÁä:%d\n", p1->name, p1->age);
}
int ComparePerson(void* p1, void* p2)
{
	Person* data1 = (Person*)p1;
	Person* data2 = (Person*)p2;
	return strcmp(data1->name, data2->name) == 0 && data1->age == data2->age;
}

void test()
{
	Person p1 = { "ÕÅ·É",30 };
	Person p2 = { "ÕÔÔÆ",20 };
	Person p3 = { "¹ØÓğ",33 };
	Person p4 = { "Öî¸ğÁÁ",40 };
	Person p5 = { "Âí³¬",23 };
	Person p6 = { "»ÆÖÒ",31 };
	Dynamic* arr = InitArr(INITCAP);
	Insert(arr, &p1, 0);
	Insert(arr, &p2, 1);
	Insert(arr, &p3, 0);
	Insert(arr, &p4, 5);
	Insert(arr, &p5, -1);
	Insert(arr, &p6, 1);
	Print(arr, PrintPerson);
	//DeleteByPos(arr, 3);
	//DeleteByPos(arr, 1);
	//DeleteByPos(arr, 1);
	DeleteByData(arr, &p6, ComparePerson);
	printf("\nÉ¾³ıºó-------------\n");
	Print(arr, PrintPerson);
	//DestroyArr(arr);
	
}
int main()
{
	test();
	return 0;
}

