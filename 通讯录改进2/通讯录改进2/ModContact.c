#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
void ModContact(struct Contact* p)
{
	printf("��������Ҫ�޸ĳ�Ա������:\n");
	char arr[MAX_NAME] = { 0 };
	scanf("%s", arr);
	int ret = FindByNmae(p, arr);
	if (ret != -1)
	{
		printf("�������޸ĺ����Ϣ:\n");
		printf("����������:\n");
		scanf("%s", p->data[ret].name);
		printf("����������:\n");
		scanf("%d", &(p->data[ret].age));
		printf("�������Ա�:\n");
		scanf("%s", p->data[ret].sex);

		printf("������绰:\n");
		scanf("%s", p->data[ret].tel);
		printf("�������ַ:\n");
		scanf("%s", p->data[ret].addr);
		printf("\n\n�޸ĳɹ�\n");
	}
	else printf("Ҫ�޸ĵ��˵���Ϣ������\n");

}