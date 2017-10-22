/*
 * Part of Cosmos by OpenGenus Foundation
 * @Author: Ayush Garg 
 * @Date: 2017-10-13 18:46:12 
 * @Last Modified by: Ayush Garg
 * @Last Modified time: 2017-10-13 18:50:15
 */

#include <stdio.h>

int isPowerOf2(long long n)
{
    return n && (!(n & (n - 1)));
}
int main()
{
    long long n;
    printf("Enter number to check\n");
    scanf("%lld", &n);
    if (isPowerOf2(n))
        printf("%lld Is a power of 2\n",n);
    else
        printf("%lld Not a power of 2\n",n);
    return 0;
}