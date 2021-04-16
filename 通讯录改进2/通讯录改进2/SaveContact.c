#define _CRT_SECURE_NO_WARNINGS
#include"main.h"
void SaveContact(struct Contact* p)
{
	FILE* save = fopen("contact.txt", "w");
	if (save == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		fwrite(&p->data[i], sizeof(struct PeoInfo), 1, save); 
	}

	fclose(save);
	save = NULL;
}