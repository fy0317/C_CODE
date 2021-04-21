#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int numDecodings(char* s)
{
    int len = strlen(s);
    int* p = (int*)malloc(sizeof(int) * (len + 1));
    memset(p, 0, sizeof(int) * (len + 1));
    int cnt = 0;
    int i = 0;
    p[0] = 1;
    if (s[0] =='0') return 0;

    for (i = 1; i <= len; i++)
    {
        if (s[i - 1] != '0') p[i] += p[i - 1];
        if (i >= 2 && s[i - 2] != '0' && 10 * (s[i - 2] - '0') + s[i - 1] - '0' <= 26) p[i] = p[i - 1] + p[i - 2];
    }
    cnt = p[len];
    free(p);
    p = NULL;
    return cnt;
}
int main()
{
    char arr[] = "112230";
    int cnt = numDecodings(arr);
    printf("%d\n", cnt);
    return 0;
}