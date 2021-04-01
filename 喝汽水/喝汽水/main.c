#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int m;              //拥有的金额
	scanf("%d", &m);
	int sum = m;; //总共喝的汽水数
	int empty=0;//empty为空瓶数
	for(empty=m;empty>1;)
	{
		sum = sum + empty/2;
		empty = empty - empty/2;//空瓶数=上一次的空瓶数-换得的汽水数*2+这次换的汽水喝完后的空瓶数,即empty=empty-empty/2*2+empty/2
		                        //empty=empty-empty/2
	}
	printf("%d\n", sum);
	return 0;
}