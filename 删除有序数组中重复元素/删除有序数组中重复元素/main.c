#define _CRT_SECURE_NO_WARNINGS

//1、暴力求解

// int removeDuplicates(int* nums, int numsSize){
//     int i = 0;
//     if (numsSize <= 1)
//     return numsSize;
//     else 
//     {
//         for (i = 0; i < numsSize-1; )
//         {
//             if  (nums[i] != nums[i+1]) i++;
//             else if(nums[i] == nums[i+1])
//             {
//                 for( int j = i; j <numsSize-1; j++)
//                 {
//                     nums[j] = nums[j+1];
//                 }
//                 nums[numsSize-1] = 0;
//                 numsSize--;
//             }
//         }
//     }
//     return numsSize;

// }

// int removeDuplicates(int* nums, int numsSize){
//     int src = 1;            //dest指向处理后的数组，src指向处理前的数组，如果numsSize大于0，那么第一个元素一定要保留，所以先让src=1
//     int dest = 0;
//     if(numsSize == 0)       //如果nusSize= 0，直接返回0
//     return 0;
//     while(src < numsSize)
//     {
//         if(nums[dest] != nums[src])         //当nums[dest] != nums[src]时，说明这两个元素不相同，因此都要保存到新数组中
//         {
//             dest++;                         //但是nums[dest]的元素是已经要保存的，所以先让dest++，然后再赋值
//             nums[dest] = nums[src];         
//             src++;                          //赋值完毕，让src++，判断下一个元素是否和当前元素相同
//         }
//         else src++;                         //如果nums[dest] == nums[src]，nums[src]就不用保存，src++
//     }
//     return dest+1;                          //dest+1表示处理后数组长度
// }
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1)
        return numsSize;
    int left = 0, right = 1, dest = 0;                 //left和right相邻并同时移动，dest表示处理后数组下标
    while (right < numsSize)
    {
        if (nums[left] != nums[right])              //这两个元素不相同，将left下标的元素存储到dest中
        {
            nums[dest] = nums[left];
            left++, right++;                         //left 和right同时后移一位，dest也后移一位
            dest++;
        }
        else left++, right++;                        //两个元素相同，则只将left和right后移一位
    }
    nums[dest++] = nums[left];                      //当right越界后，最后一个数据还没有处理，将其赋值给nums[dest]，同时dest++
    return dest;
}
int main()
{
    int arr[] = { 1,2,2,3,3,4,4,5 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int ret = removeDuplicates(arr, sz);
    return 0;
}