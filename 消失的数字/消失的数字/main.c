#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int missingNumber(int* nums, int numsSize) {
    int i = 0;
    int ret = 0;
    int* p;
    p = (int*)malloc((numsSize + 1) * sizeof(int));
    for (i = 0; i <= numsSize; i++)
    {
        *(p + i) = i;
    }
    for (i = 0; i < numsSize; i++)
    {
        *(p + *(nums + i)) = 0;
    }
    for (i = 0; i <= numsSize; )
    {
        if (*(p + i) == 0) i++;
        else {
            ret = *(p + i);
            free(p);
            break;
        }
    }
    return ret;

}
int main()
{
    int nums[] = { 9,6,4,2,3,5,7,0,1 };
    int sz = sizeof(nums) / sizeof(nums[0]);
    int ret =missingNumber(nums, sz);
    printf("消失的数字是:%d\n", ret);
    return 0;

}