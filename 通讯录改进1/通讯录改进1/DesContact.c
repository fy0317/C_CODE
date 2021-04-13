#define _CRT_SECURE_NO_WARNINGS
#include"main.h"
void DesContact(struct Contact* p)
{
	free(p->data);
	p->data = NULL;
}