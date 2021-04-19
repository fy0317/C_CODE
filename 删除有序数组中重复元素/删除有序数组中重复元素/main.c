#define _CRT_SECURE_NO_WARNINGS

//1���������

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
//     int src = 1;            //destָ���������飬srcָ����ǰ�����飬���numsSize����0����ô��һ��Ԫ��һ��Ҫ��������������src=1
//     int dest = 0;
//     if(numsSize == 0)       //���nusSize= 0��ֱ�ӷ���0
//     return 0;
//     while(src < numsSize)
//     {
//         if(nums[dest] != nums[src])         //��nums[dest] != nums[src]ʱ��˵��������Ԫ�ز���ͬ����˶�Ҫ���浽��������
//         {
//             dest++;                         //����nums[dest]��Ԫ�����Ѿ�Ҫ����ģ���������dest++��Ȼ���ٸ�ֵ
//             nums[dest] = nums[src];         
//             src++;                          //��ֵ��ϣ���src++���ж���һ��Ԫ���Ƿ�͵�ǰԪ����ͬ
//         }
//         else src++;                         //���nums[dest] == nums[src]��nums[src]�Ͳ��ñ��棬src++
//     }
//     return dest+1;                          //dest+1��ʾ��������鳤��
// }
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1)
        return numsSize;
    int left = 0, right = 1, dest = 0;                 //left��right���ڲ�ͬʱ�ƶ���dest��ʾ����������±�
    while (right < numsSize)
    {
        if (nums[left] != nums[right])              //������Ԫ�ز���ͬ����left�±��Ԫ�ش洢��dest��
        {
            nums[dest] = nums[left];
            left++, right++;                         //left ��rightͬʱ����һλ��destҲ����һλ
            dest++;
        }
        else left++, right++;                        //����Ԫ����ͬ����ֻ��left��right����һλ
    }
    nums[dest++] = nums[left];                      //��rightԽ������һ�����ݻ�û�д������丳ֵ��nums[dest]��ͬʱdest++
    return dest;
}
int main()
{
    int arr[] = { 1,2,2,3,3,4,4,5 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int ret = removeDuplicates(arr, sz);
    return 0;
}