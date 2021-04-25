#define _CRT_SECURE_NO_WARNINGS
#include"config.h"

//获取有效的行数
int getFileLine(const char* filePath)
{
	FILE* file = fopen(filePath, "r");
	if (file == NULL)
	{
		perror("文件打开失败");
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

//判断有效行
int isInvalidLine(char* str)
{
	if (str[0] == '\n' || strchr(str, ':') == NULL) //strchr，在str中查找字符 ':'
		return 0;
	return 1;
}

//文件解析
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
			//清空key和value的数据
			memset(config[i].key, 0, 64);
			memset(config[i].value, 0, 64);

			char* pos = strchr(buf, ':');
			//截取key的数据
			strncpy(config[i].key, buf, pos - buf);
			//截取value数据
			strncpy(config[i].value, pos + 1, strlen(pos + 1) - 1);	//减1是为了不要换行符\0
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
void freeSpace(struct ConfigInfo* configInfo)	//释放内存
{
	if (configInfo == NULL) return;
	free(configInfo);
	configInfo = NULL;
}