#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

int cnt = 0;
int Cmp_Byname(const void* e1, const void* e2)
{
	cnt++;
	return strcmp ( ( (struct PeoInfo*) e1)->name, ( (struct PeoInfo*) e2 )->name );
}

void SortContact(struct Contact* p)
{
	int sz_ = sizeof(p->data) / sizeof(p->data[0]);
	qsort(p->data, p->sz , sizeof(p->data[0]),Cmp_Byname);  //p->sz 表示当前已有元素个数
	printf("排序成功\n");
}