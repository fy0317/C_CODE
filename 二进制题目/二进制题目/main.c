#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//二进制中1的个数：
void test1()
{
	int n = 0;
	scanf("%d", &n);
	int cnt = 0;
	//方法1：
	for (int i = 0; i < 32; i++)
	{
		if ((n & (1 << i)) == (1 << i))
			cnt++ ;
	}
	printf("%d\n", cnt);
	//方法2：
	cnt = 0;
	while (n)
	{
		cnt++;
		n &= n - 1;
	}
	printf("%d\n", cnt);
}


//交换二进制的基偶位
//0101  0x5
//1010  0xa

//9 1001   0110
//8 1000   0100
//1010 0101
//10101010 10101010 10101010 10101010
//10101010 10101010 10101010 10101001
//11010101 01010101 01010101 01010110
// -1431655766
//01010101 01010101 01010101 01010101
//1,431,655,765
void test2()
{
	int n = 0;
	scanf("%d", &n);
	int x1 = 0x55555555 & n;
	int x2 = 0xaaaaaaaa & n;
	printf("%d\n", (x1 << 1) ^ (x2 >> 1));


}

//判断一个小数是否能用二进制精确表示
void test3()
{
	double x;
	scanf("%lf", &x);
	int cnt = 0;
	while (x && cnt <8)
	{
		x *= 2;
		if (x >= 1)
			x -= 1;
		cnt++;
	}
	if (x == 0)
		printf("可以");
	else printf("不可以");
}

//一个数组中除了一个数以外，其他数均只出现k次，找出这个没重复的数

//暴力求解：
int find_num(int* arr, int sz, int k)
{
	int cnt = 0;
	int i, j;
	for (i = 0; i < sz; i++)
	{
		cnt = 0;
		for (j = 0; j < sz; j++)
		{
			if (arr[i] == arr[j])
				cnt++;
			if (cnt > 1)
				break;
		}
		if (cnt == 1)
			return arr[i];
	}
}

//不进位加法求解  将原数组的每个数转化为k进制表示的数
//k进制的异或
//k个相同的k进制的数进行无进位加法，最后的结果为0 
int find_num1(int* arr, int sz, int k)
{
	int k_size[13][10] = { 0 };
	int i,j;
	//将原数组中元素转化为k进制
	for (i = 0; i < sz; i++)
	{
		int tmp = arr[i];
		for (j = 0; j < 10 && tmp; j++)
		{
			k_size[i][j] = tmp % k;
			tmp /= k;
		}
	}

	//将转化位k进制的数进行无进位加法,存放在tmp[]中
	int tmp[10] = { 0 };
	for (j = 0; j < 10; j++)
	{
		for (i = 0; i < 13; i++)
		{
			tmp[j] += k_size[i][j];
			tmp[j] %= k;
		}
	}
	//最后的tmp中存放的数就是没有重复的数，将其转换为10进制
	int ret = 0;
	for (i = 0; i < 10; i++)
	{
		ret += tmp[i] * pow(k, i);
	}
	return ret;

}
void test4()
{
	int  arr[] = { 1 ,1 ,1, 3,3,3,5 ,5,5,9,8 ,8 ,8 };
	int k = 3;
	int size = sizeof(arr) / sizeof(int);
	int ret = find_num(arr, size,  k);
	printf("%d\n", ret);
	ret = find_num1(arr, size, k);
	printf("%d\n", ret);
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}

