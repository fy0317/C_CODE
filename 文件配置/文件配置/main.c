#define _CRT_SECURE_NO_WARNINGS
#include"config.h"

int main()
{
	int lines = getFileLine("test.txt");
//	printf("%d", lines);
	struct ConfigInfo* configInfo = NULL;
	parseFile("test.txt", lines, &configInfo);
	printf("heroId = %s\n", getValueByKey("heroId", configInfo, lines));
	printf("heroName = %s\n", getValueByKey("heroName", configInfo, lines));
	printf("heroAtk = %s\n", getValueByKey("heroAtk", configInfo, lines));
	printf("heroInfo = %s\n", getValueByKey("heroInfo", configInfo, lines));
	freeSpace(configInfo);
	configInfo = NULL;
	return 0;
}