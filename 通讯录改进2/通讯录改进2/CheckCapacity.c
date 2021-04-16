#define _CRT_SECURE_NO_WARNINGS
#include"main.h"
void CheckCapacity(struct Contact* p)
{
	if (p->capacity == p->sz)
	{
		struct PeoInfo* tmp = (struct PeoInfo*)(realloc( p->data , sizeof(struct PeoInfo) * ( (p->capacity) + 2) ) );
		if (tmp != NULL)
		{
			printf("À©ÈÝ³É¹¦\n");
			p->data = tmp;
			p->capacity += 2;
		}
	}
}