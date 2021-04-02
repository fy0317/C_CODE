#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') +( killer == 'd') +( killer != 'd') == 3)
		{
			printf("killer=%c", killer);
			break;
		}
	}
	return 0;
}