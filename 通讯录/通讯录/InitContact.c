#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
void InitContact(struct Contact* p)
{
	memset(p->data, 0, sizeof(p->data));
	p->sz = 0;
}