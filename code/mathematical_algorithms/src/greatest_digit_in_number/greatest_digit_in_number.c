#include<stdio.h>

int 
greatest_digit(int n)
{
    int max_digit = n % 10;
    while(n) {
        max_digit = (max_digit < n % 10) ? n % 10 : max_digit;
        n /= 10;
    }
    return (max_digit);
}

int 
main()
{
    int n;
    scanf("%d", &n);
    printf("Greatest digit is %d :\n", greatest_digit(n));
    
    return (0);
}
