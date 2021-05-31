#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
double myPow(double x, int n) 
{
    double sum = 1;
    if (n == 0) return sum;
    else if (n > 0)
    {
        if (n % 2)
        {
            double tmp = myPow(x, n / 2);
            sum = x * tmp * tmp;
        }
        else
        {
            double tmp = myPow(x, n / 2);
            sum = tmp * tmp;
        }
    }
    else
    {
        if (n == -2147483648)
        {
            n++;
            sum = myPow(x, -n);
            sum *= x;
        }
        else sum = myPow(x, -n);
        sum = 1 / sum;
    }
    return sum;
}
void test1()
{
    double x = 0;
    int n = 0;
    scanf("%lf %d", &x, &n);
    double ret = myPow(x, n);
    printf("%lf", ret);
}
int main()
{
    test1();
	return 0;
}


