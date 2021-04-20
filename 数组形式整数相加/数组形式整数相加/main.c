#define _CRT_SECURE_NO_WARNINGS
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<assert.h>
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    assert(num);
    assert(returnSize);
    int cnt = 0;        //进位
    int sz = 0;         //返回数组的大小
    int tmp = k;
    int   i = 0;
    while (tmp)          //求出k的长度
    {
        tmp /= 10;
        sz++;
    }
    sz = numSize >= sz ? (numSize + 1) : (sz + 1);      //最后一位可能进位，新数组大小要比k长度和num的长度大1
    int* arr = (int*)malloc(sizeof(int) * sz);         //给返回数组开辟空间
    for (i = 0; i < sz; i++)                           //初始化
    {
        arr[i] = 0;
    }
    i = 0;
    while (numSize - 1 - i >= 0 || k)                        //当num数组没有计算完或者k不为0时
    {
        //如果num数组没计算完，让num当前位和k%10后相加
        if (numSize - 1 - i >= 0) tmp = num[numSize - 1 - i] + k % 10;
        else tmp = k % 10;        //如果num已经计算完了，只让k%10
        arr[sz - 1 - i] = (tmp + cnt) % 10;     //返回数组当前位存放的数，等于tmp+上次一的进位cnt，然后%10
        cnt = (tmp + cnt) / 10;             //计算完后，计算下一位的进位
        k /= 10;
        i++;
    }
    arr[0] = cnt;                           //让arr[0]等于最后一次的进位
    if (arr[0] == 0)                         //arr[0]=0,说明最后一次进位为0
    {
        //int *p = (int*)realloc(arr+1,sizeof(int) * (sz - 1));
        *returnSize = sz - 1;
        return arr + 1;

    }
    else
    {
        *returnSize = sz;
        return arr;
    }
}