#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int m;              //ӵ�еĽ��
	scanf("%d", &m);
	int sum = m;; //�ܹ��ȵ���ˮ��
	int empty=0;//emptyΪ��ƿ��
	for(empty=m;empty>1;)
	{
		sum = sum + empty/2;
		empty = empty - empty/2;//��ƿ��=��һ�εĿ�ƿ��-���õ���ˮ��*2+��λ�����ˮ�����Ŀ�ƿ��,��empty=empty-empty/2*2+empty/2
		                        //empty=empty-empty/2
	}
	printf("%d\n", sum);
	return 0;
}