#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
int FindByNmae(struct Contact* p, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		if (strcmp(name, p->data[i].name) == 0)
			return i;
	}
	return -1;
}