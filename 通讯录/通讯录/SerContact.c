#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
void SerContact(const struct Contact* p)
{
	printf("请输入想要查找元素的姓名\n");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	int ret = FindByNmae(p, name);
	if(ret == -1)
		printf("没有找到\n");
	else
	{
		printf("找到了:\n");
		printf("%-10s\t%-5s\t%-5s\t%-12s\t%-10s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-10s\t%-5d\t%-5s\t%-12s\t%-10s\n", p->data[ret].name,
			p->data[ret].age,
			p->data[ret].sex,
			p->data[ret].tel,
			p->data[ret].addr);
	}
}