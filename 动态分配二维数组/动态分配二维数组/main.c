#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m = 0;
    int n = 0;
    scanf("%d %d", &m, &n);
    m *= 2;
    int** arr = (int**)malloc(sizeof(int*) * m);
    int i = 0;
    int j = 0;
    for (i = 0; i < m; i++)
        arr[i] = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    }
    int cnt = 0;
    for (i = 0; i < m / 2; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == arr[m / 2 + i][j])
                cnt++;
        }
    }
    printf("%.2f\n", cnt * 100.0 / (m / 2 * n));
    for (i = 0; i < m; i++)
        free(arr[i]);
    free(arr);
    return 0;
}