#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
void InitContact(struct Contact* p)
{
	//��⵱ǰͨѶ¼�����������������������
	p->data = (struct PeoInfo*)malloc(sizeof(struct PeoInfo) * INITIAL_SZ);
	p->capacity = INITIAL_SZ;
	p->sz = 0;
}