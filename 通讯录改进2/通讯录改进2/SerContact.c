#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
void SerContact(const struct Contact* p)
{
	printf("��������Ҫ����Ԫ�ص�����\n");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	int ret = FindByNmae(p, name);
	if(ret == -1)
		printf("û���ҵ�\n");
	else
	{
		printf("�ҵ���:\n");
		printf("%-10s\t%-5s\t%-5s\t%-12s\t%-10s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-10s\t%-5d\t%-5s\t%-12s\t%-10s\n", p->data[ret].name,
			p->data[ret].age,
			p->data[ret].sex,
			p->data[ret].tel,
			p->data[ret].addr);
	}
}