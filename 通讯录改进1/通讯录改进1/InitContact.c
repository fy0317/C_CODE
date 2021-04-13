#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
void InitContact(struct Contact* p)
{
	//检测当前通讯录容量，如果容量不够则扩容
	p->data = (struct PeoInfo*)malloc(sizeof(struct PeoInfo) * INITIAL_SZ);
	p->capacity = INITIAL_SZ;
	p->sz = 0;
}