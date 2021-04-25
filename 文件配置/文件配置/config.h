#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ConfigInfo
{
	char key[64];
	char value[64];
};
int getFileLine(const char* filePath);				//��ȡ�ļ���Ч����
int isInvalidLine(char* str);						//�ж��Ƿ�����Ч��
void parseFile(const char* filePath, int lines, struct ConfigInfo** configInfo);	//�ļ����� 
char* getValueByKey(char* key, struct ConfigInfo* configInfo, int lines);	//����key��ȡ��Ӧvalueֵ
void freeSpace(struct ConfigInfo* configInfo);	//�ͷ��ڴ�