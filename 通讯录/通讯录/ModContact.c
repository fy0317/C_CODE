#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
void ModContact(struct Contact* p)
{
	printf("请输入想要修改成员的姓名:\n");
	char arr[MAX_NAME] = { 0 };
	scanf("%s", arr);
	int ret = FindByNmae(p, arr);
	if (ret != -1)
	{
		printf("请输入修改后的信息:\n");
		printf("请输入名字:\n");
		scanf("%s", p->data[ret].name);
		printf("请输入年龄:\n");
		scanf("%d", &(p->data[ret].age));
		printf("请输入性别:\n");
		scanf("%s", p->data[ret].sex);

		printf("请输入电话:\n");
		scanf("%s", p->data[ret].tel);
		printf("请输入地址:\n");
		scanf("%s", p->data[ret].addr);
		printf("\n\n修改成功\n");
	}
	else printf("要修改的人的信息不存在\n");

}