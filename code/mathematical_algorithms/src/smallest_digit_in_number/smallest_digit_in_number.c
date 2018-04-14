#include<stdio.h>
// Part of Cosmos by OpenGenus Foundation
int 
smallest_digit(int n)
{
    int min_digit = n % 10;
    while (n) {
        min_digit = (min_digit > n % 10) ? n % 10 : min_digit;
        n /= 10;
    }
    return (min_digit);
}

int 
main()
{
    int n;
    scanf("%d", &n);
    printf("smallest digit is %d :\n",smallest_digit(n));
    
    return (0);
}
