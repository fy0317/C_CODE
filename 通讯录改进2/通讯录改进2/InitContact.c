#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
void InitContact(struct Contact* p)
{
	p->data = (struct PeoInfo*)malloc(sizeof(struct PeoInfo) * INITIAL_SZ);
	p->capacity = INITIAL_SZ;
	p->sz = 0;
	//���ļ��д�ŵ���Ϣ�����ص�ͨѶ¼��
	FILE* Read = fopen("contact.txt", "r");
	if (Read == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	struct PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(struct PeoInfo), 1, Read))
	{
		CheckCapacity(p);
		p->data[p->sz] = tmp;
		p->sz++;
	}
	fclose(Read);
	Read = NULL;
}