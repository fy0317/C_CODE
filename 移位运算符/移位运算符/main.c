#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	int a = 1073741825;
//	int c = 2 * a;
//	int b = a << 1;
//	printf("%d\n", b);
//	printf("%d\n", c);
//	return 0;
//}
//int main()
//{
//    int n = 0, m = 0;
//    scanf("%d %d", &n, &m);
//    n = n ^ m;
//    int cnt = 0;
//    while (n)
//    {
//        if (n & 1)
//            cnt++;
//        n >>= 1;
//    }
//    printf("%d", cnt);
//    return 0;
//}
//int main()
//{
//	int n = 0;
//	int odd[16] = { 0 };	//存放奇数位
//	int even[16] = { 0 };	//存放偶数位
//	scanf("%d", &n);
//	//输入9
//	//   0000 0000 0000 0000 0000 0000 0000 1001
//	//   奇数位  10 00 00 00 00 00 00 00 --> 00 00 00 00 00 00 00 01
//	//	 偶数位  01 00 00 00 00 00 00 00 --> 00 00 00 00 00 00 00 10
//	//获取奇数位
//	int i = 0;
//	int tmp = n;
//	for (i = 0; i < 16; i++)
//	{
//		odd[15 - i] = n >> (2 * i) & 1;
//	}
//	//获取偶数位
//	for (i = 0; i < 16; i++)
//	{
//		even[15 - i] = n >> (2 * i + 1) & 1;
//	}
//	for (i = 0; i < 16; i++)
//		printf("%d", odd[i]);
//	printf("\n");
//	for (i = 0; i < 16; i++)
//		printf("%d", even[i]);
//	return 0;
//}
//int main()
//{
//	int cnt = 0;
//	int n = 0;
//	scanf("%d", &n);
//	while (n)
//	{
//		if (n & 1) cnt++;
//		n >>= 1;
//	}
//	printf("%d\n", cnt);
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("交换前：a = %d，b = %d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("交换后：a = %d，b = %d\n", a, b);
//	return 0;
//}
//int main()
//{
//	unsigned un = 3000000000;
//	short end = 200;
//	long big = 65537;
//	long long verybig = 12345678908642;
//	printf("un = %u and not %d\n", un, un);
//	printf("end = %hd and %d\n", end, end);
//	printf("big = %ld and not %hd\n", big, big);
//	printf("verybig = %lld and not %ld\n", verybig, verybig);
//	return 0;
//}
int main()
{
	float toobig = 1.4e38 * 100.0f;
	printf("%f", toobig);
	return 0;
}