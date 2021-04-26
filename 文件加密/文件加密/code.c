#define _CRT_SECURE_NO_WARNINGS
#include"code.h"


//文件加密
void codeFile(char* sourceFile, char* destFile)
{
	FILE* p1 = fopen(sourceFile, "r");
	FILE* p2 = fopen(destFile, "w");
	if (!p1 || !p2)
	{
		perror("文件打开失败");
	}
	char c = 0;
	while ((c = fgetc(p1)) != EOF)
	{
		short tmp = (short)c;
		tmp <<= 4;
		tmp |= 0x8000;
		tmp = tmp + rand() % 16;
		fprintf(p2, "%d", tmp);
	}
	fclose(p1);
	fclose(p2);
}

//文件解密
void decodeFile(char* sourceFile, char* destFile)
{
	FILE* p1 = fopen(sourceFile, "r");
	FILE* p2 = fopen(destFile, "w");
	if (!p1 || !p2)
	{
		perror("文件打开失败");
		return;
	} 
	short tmp = 0;
	while (!feof(p1))
	{
		fscanf(p1, "%hd", &tmp);
		tmp <<= 1;
		tmp >>= 5;
		char c = (char)tmp;
		fputc(c, p2);
	}
	fclose(p1);
	fclose(p2);

}