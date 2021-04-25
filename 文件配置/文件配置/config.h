#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ConfigInfo
{
	char key[64];
	char value[64];
};
int getFileLine(const char* filePath);				//获取文件有效行数
int isInvalidLine(char* str);						//判断是否是有效行
void parseFile(const char* filePath, int lines, struct ConfigInfo** configInfo);	//文件解析 
char* getValueByKey(char* key, struct ConfigInfo* configInfo, int lines);	//根据key获取对应value值
void freeSpace(struct ConfigInfo* configInfo);	//释放内存