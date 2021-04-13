#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
void DelContact(struct Contact* p)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入想要删除的成员的名字\n");
	scanf("%s", name);
	int ret = FindByNmae(p, name);
	if (ret == -1)
		printf("所要删除的元素不存在\n");
	else
	{
		int i = 0;
		for (i = ret - 1; i < p->sz-1; i++)
		{
			p->data[i] = p->data[i + 1];
			//strcpy(p->data[i].name, p->data[i + 1].name);
			//strcpy(p->data[i].sex, p->data[i + 1].sex);
			//strcpy(p->data[i].tel, p->data[i + 1].tel);
			//strcpy(p->data[i].addr, p->data[i + 1].addr);
			//p->data[i].age = p->data[i + 1].age;
		}
		p->sz--;
		printf("删除成功\n");
	}
	
}