#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
void AddContact(struct Contact * p)
{
	if (p->sz == MAX)
		printf("通讯录已满，无法增加\n");
	else
	{
		printf("请输入名字:\n");
		scanf("%s", p->data[p->sz].name);
		printf("请输入年龄:\n");
		scanf("%d", &(p->data[p->sz].age));

		printf("请输入性别:\n");
		scanf("%s", p->data[p->sz].sex);

		printf("请输入电话:\n");
		scanf("%s", p->data[p->sz].tel);

		printf("请输入地址:\n");
		scanf("%s", p->data[p->sz].addr);
	}
	p->sz++;
	printf("添加成功\n");
}