#define _CRT_SECURE_NO_WARNINGS
#include"code.h"

void test1()
{
	srand((unsigned int)time(NULL));
	codeFile("test.txt", "�����ļ�.txt");
	decodeFile("�����ļ�.txt", "�����ļ�.txt");
}
int main()
{
	test1();
	return 0;
}