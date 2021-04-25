#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Person
{
	char* name;
	int age;
}Person;

//void Print_Person(Person arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		printf("name = %s  age = %d\n", arr[i].name, arr[i].age);
//	}
//}
//void test1()
//{
//	Person arr[] = { {"aaa",10}, {"bbb",20},{"ccc",30} };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	Print_Person(arr, len);
//}
//void test2()
//{
//	Person p1 = { "Tom", 28 };
//	Person p2 = { "Jerry", 29 };
//	p1 = p2;
//	printf("p1 name = %s  p1 age = %d\n", p1.name, p1.age);
//	printf("p2 name = %s  p2 age = %d\n", p2.name, p2.age);
//}
//typedef struct Person1
//{
//	char* name;
//	int age;
//}Person1;
//
//void test3()
//{
//	Person1 p1;
//	Person1 p2;
//	p1.name = (char*)malloc(sizeof(char) * 64);
//	strcpy(p1.name, "Tom");
//	p1.age = 18;
//	p2.name = (char*)malloc(sizeof(char) * 64);
//	strcpy(p2.name, "Jerry");
//	p2.age = 19;	
//	p1 = p2;
//	printf("p1 name = %s  p1 age = %d\n", p1.name, p1.age);
//	printf("p2 name = %s  p2 age = %d\n", p2.name, p2.age);
//	if (p1.name != NULL)
//	{
//		free(p1.name);
//		p1.name = NULL;
//	}
//	if (p2.name != NULL)
//	{
//		free(p2.name);
//		p2.name = NULL;
//	}
//}

Person** allocateSpace()
{
	Person** tmp =malloc(sizeof(Person*) * 3);
	if (tmp != NULL)
	{
		for (int i = 0; i < 3; i++)
		{
			tmp[i] = malloc(sizeof(Person));
			if (tmp[i] != NULL)
			{
				tmp[i]->name = malloc(sizeof(char) * 20);
				if (tmp[i]->name != NULL)
				{
					sprintf(tmp[i]->name, "name_%d", i);
					tmp[i]->age = i + 20;
				}
			}
		}
	}
	return tmp;
}

void printPerson(Person** pp, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("姓名:  %s    age:  %d\n", pp[i]->name, pp[i]->age);
	}
}
void freeSpace(Person** pp, int len)
{
	if (pp == NULL || len < 0) return;
	for (int i = 0; i < len; i++)
	{
		if (pp[i] != NULL)
		{
			if (pp[i]->name != NULL)
			{
				free(pp[i]->name);
				pp[i]->name = NULL;
			}
			free(pp[i]);
			pp[i] = NULL;
		}
	}

}
test4()
{
	Person** pp = allocateSpace();			//申请空间
	printPerson(pp, 3);			//打印信息
	freeSpace(pp, 3);			//释放空间
	free(pp);
	pp = NULL;
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;

}