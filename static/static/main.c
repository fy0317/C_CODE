#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4 };
//	int* p2 = (int*)((int)arr + 1);
//	printf("%#x ", *p2);
//	return 0;
//}
//int main()
//{
//	//int arr[3][2] = { 1,3,5 };
//	//int* p;
//	//p = arr[0];
//	//printf("%d", p[0]);
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}


//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	return 0;
//}
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	return 0;
}

