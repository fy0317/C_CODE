#define _CRT_SECURE_NO_WARNINGS
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<assert.h>
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    assert(num);
    assert(returnSize);
    int cnt = 0;        //��λ
    int sz = 0;         //��������Ĵ�С
    int tmp = k;
    int   i = 0;
    while (tmp)          //���k�ĳ���
    {
        tmp /= 10;
        sz++;
    }
    sz = numSize >= sz ? (numSize + 1) : (sz + 1);      //���һλ���ܽ�λ���������СҪ��k���Ⱥ�num�ĳ��ȴ�1
    int* arr = (int*)malloc(sizeof(int) * sz);         //���������鿪�ٿռ�
    for (i = 0; i < sz; i++)                           //��ʼ��
    {
        arr[i] = 0;
    }
    i = 0;
    while (numSize - 1 - i >= 0 || k)                        //��num����û�м��������k��Ϊ0ʱ
    {
        //���num����û�����꣬��num��ǰλ��k%10�����
        if (numSize - 1 - i >= 0) tmp = num[numSize - 1 - i] + k % 10;
        else tmp = k % 10;        //���num�Ѿ��������ˣ�ֻ��k%10
        arr[sz - 1 - i] = (tmp + cnt) % 10;     //�������鵱ǰλ��ŵ���������tmp+�ϴ�һ�Ľ�λcnt��Ȼ��%10
        cnt = (tmp + cnt) / 10;             //������󣬼�����һλ�Ľ�λ
        k /= 10;
        i++;
    }
    arr[0] = cnt;                           //��arr[0]�������һ�εĽ�λ
    if (arr[0] == 0)                         //arr[0]=0,˵�����һ�ν�λΪ0
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