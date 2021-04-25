#define _CRT_SECURE_NO_WARNINGS
#include"config.h"

//��ȡ��Ч������
int getFileLine(const char* filePath)
{
	FILE* file = fopen(filePath, "r");
	if (file == NULL)
	{
		perror("�ļ���ʧ��");
		return -1;
	}
	char buf[1024] = { 0 };
	int line = 0;
	while (fgets(buf, 1024, file) != NULL)
	{
		if(isInvalidLine(buf))
			line++;
	}
	return line;
}

//�ж���Ч��
int isInvalidLine(char* str)
{
	if (str[0] == '\n' || strchr(str, ':') == NULL) //strchr����str�в����ַ� ':'
		return 0;
	return 1;
}

//�ļ�����
void parseFile(const char* filePath, int lines, struct ConfigInfo** configInfo)
{
	struct ConfigInfo* config = malloc(sizeof(struct ConfigInfo) * lines);
	if (config == NULL) return;
	FILE* file = fopen(filePath, "r");
	if (file == NULL) return;
	char buf[1024] = { 0 };
	int i = 0;
	while (fgets(buf, 1024, file) != NULL)
	{
		if (isInvalidLine(buf))
		{
			//buf = keroId:1111\n\0\0
			//���key��value������
			memset(config[i].key, 0, 64);
			memset(config[i].value, 0, 64);

			char* pos = strchr(buf, ':');
			//��ȡkey������
			strncpy(config[i].key, buf, pos - buf);
			//��ȡvalue����
			strncpy(config[i].value, pos + 1, strlen(pos + 1) - 1);	//��1��Ϊ�˲�Ҫ���з�\0
			//printf("key = %s\n", config[i].key);
			//printf("value = %s\n", config[i].value);
			i++;
		}
		memset(buf, 0, 1024);
	}
	*configInfo = config;
}
char* getValueByKey(char* key, struct ConfigInfo* configInfo, int lines)
{
	for (int i = 0; i < lines; i++)
	{
		if (strcmp(configInfo[i].key, key) == 0)
			return configInfo[i].value;
	}
	return NULL;
}
void freeSpace(struct ConfigInfo* configInfo)	//�ͷ��ڴ�
{
	if (configInfo == NULL) return;
	free(configInfo);
	configInfo = NULL;
}