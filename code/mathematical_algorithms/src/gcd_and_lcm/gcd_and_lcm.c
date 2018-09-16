/* Part of Cosmos by OpenGenus Foundation */
/* Created by Shubham Prasad Singh on 13/10/2017 */
/* GCD and LCM */

#include<stdio.h>

int 
_gcd(int a, int b)  ////////// Euclid Algorithm
{
    if(!b)
        return (a);
    return (_gcd(b, a % b));
}

int
main()
{
    int a, b;
    printf("Enter the numbers\n");
    scanf("%d%d", &a, &b);

    int gcd = _gcd(a, b);
    int lcm = a * b / gcd;

    printf("GCD is %d\nLCM is %d \n", gcd, lcm);

    return (0);
}
