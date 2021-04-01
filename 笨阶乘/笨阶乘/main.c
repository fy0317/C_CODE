#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int clumsy(int N)
//{
//    int sum = 0;
//    if (N < 4)
//    {
//        switch (N)
//        {
//        case 1: return N;
//        case 2: return N * (N - 1);
//        case 3:return N * (N - 1) / (N - 2);
//
//        }
//    }
//    if (N >= 4)
//    {
//        sum = sum + N * (N - 1) / (N - 2) + N - 3;
//        N = N - 4;
//    }
//    while (N >= 4)
//    {
//        sum = sum - N * (N - 1) / (N - 2) + N - 3;
//        N = N - 4;
//    }
//    switch (N)
//    {
//    case 1:
//    {
//        sum = sum - N;
//        break;
//    }
//    case 2:
//    case 3:
//    {
//        sum = sum - N * (N - 1);
//        break;
//    }
//    }
//    return sum;
//}
int clumsy(int N)
{
    if (N == 1 || N == 2)
        return N;
    if (N == 3 || N == 4)
        return N + 3;
    int arr[] = { 1,2,2,-1 };
    return N + arr[N % 4];
}
int main()
{
    int N, sum;
    scanf("%d", &N);
    sum = clumsy(N);
    printf("%d\n", sum);
    return 0;
}