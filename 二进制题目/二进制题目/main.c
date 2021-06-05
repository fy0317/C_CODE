#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//��������1�ĸ�����
void test1()
{
	int n = 0;
	scanf("%d", &n);
	int cnt = 0;
	//����1��
	for (int i = 0; i < 32; i++)
	{
		if ((n & (1 << i)) == (1 << i))
			cnt++ ;
	}
	printf("%d\n", cnt);
	//����2��
	cnt = 0;
	while (n)
	{
		cnt++;
		n &= n - 1;
	}
	printf("%d\n", cnt);
}


//���������ƵĻ�żλ
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

//�ж�һ��С���Ƿ����ö����ƾ�ȷ��ʾ
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
		printf("����");
	else printf("������");
}

//һ�������г���һ�������⣬��������ֻ����k�Σ��ҳ����û�ظ�����

//������⣺
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

//����λ�ӷ����  ��ԭ�����ÿ����ת��Ϊk���Ʊ�ʾ����
//k���Ƶ����
//k����ͬ��k���Ƶ��������޽�λ�ӷ������Ľ��Ϊ0 
int find_num1(int* arr, int sz, int k)
{
	int k_size[13][10] = { 0 };
	int i,j;
	//��ԭ������Ԫ��ת��Ϊk����
	for (i = 0; i < sz; i++)
	{
		int tmp = arr[i];
		for (j = 0; j < 10 && tmp; j++)
		{
			k_size[i][j] = tmp % k;
			tmp /= k;
		}
	}

	//��ת��λk���Ƶ��������޽�λ�ӷ�,�����tmp[]��
	int tmp[10] = { 0 };
	for (j = 0; j < 10; j++)
	{
		for (i = 0; i < 13; i++)
		{
			tmp[j] += k_size[i][j];
			tmp[j] %= k;
		}
	}
	//����tmp�д�ŵ�������û���ظ�����������ת��Ϊ10����
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

