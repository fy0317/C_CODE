#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
void AddContact(struct Contact * p)
{

	//���ͨѶ¼����
	CheckCapacity(p);
	//��������
	printf("����������:\n");
	scanf("%s", p->data[p->sz].name);
	printf("����������:\n");
	scanf("%d", &(p->data[p->sz].age));

	printf("�������Ա�:\n");
	scanf("%s", p->data[p->sz].sex);

	printf("������绰:\n");
	scanf("%s", p->data[p->sz].tel);

	printf("�������ַ:\n");
	scanf("%s", p->data[p->sz].addr);
	
	p->sz++;
	printf("��ӳɹ�\n");
}