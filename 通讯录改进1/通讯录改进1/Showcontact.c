#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
void Showcontact(const struct Contact* p)
{
	if (p->sz == 0)
		printf("通讯录为空\n");
	else
	{
		int i = 0;
		printf("%-10s\t%-5s\t%-5s\t%-12s\t%-10s\n","姓名","年龄","性别","电话","地址");
		for (i = 0; i < p->sz; i++)
		{
			printf("%-10s\t%-5d\t%-5s\t%-12s\t%-10s\n", p->data[i].name,
				p->data[i].age, 
				p->data[i].sex,
				p->data[i].tel,
				p->data[i].addr);
		}
	}
}