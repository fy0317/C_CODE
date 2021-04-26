#define _CRT_SECURE_NO_WARNINGS
#include"code.h"

void test1()
{
	srand((unsigned int)time(NULL));
	codeFile("test.txt", "加密文件.txt");
	decodeFile("加密文件.txt", "解密文件.txt");
}
int main()
{
	test1();
	return 0;
}