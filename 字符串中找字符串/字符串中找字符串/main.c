#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int strStr(char* haystack, char* needle) {
    int len2 = strlen(needle);
    int len1 = strlen(haystack);
    if (len2 == 0) return 0;
    int  now = 0;
    int  cnt = 0;
    if (needle == NULL) return 0;
    for (int i = 0; i < len1; i++)
    {
        now = 0;
        for (int j = i; j <=i+len2&&j<len1; j++)
        {
            if (haystack[j] == needle[now] && now == 0) cnt = j;
            if (haystack[j] == needle[now])
            {
                now++;
                if (now == len2)
                    return  cnt;
            }
            else now = 0;
        }
        //  for(int j = i; (j <i + len2) &&  j<len1; j++)
        //  {
        //     if(haystack[i] == needle[now])
        //     {
        //         now++;
        //         if(now == len2)
        //             return len1-i+1;
        //     }
        //     else if(haystack[i] == needle[0]) 
        //     {
        //         now = 1;
        //     }
        //     else now =  0;
        // }
    }
    return -1;
}
int main()
{
    char  arr1[] = "aabaabbbaabbbbabaaab";
    char arr2[] = "abaa";
    int  ret = strStr(arr1, arr2);
    printf("%d ", ret);
    return 0;

}
