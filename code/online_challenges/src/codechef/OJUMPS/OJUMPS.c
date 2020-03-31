#include<stdio.h>

int main() 
{
    long long int a;
    scanf("%lld", & a);
    long long int b = a % 6;
    if (b == 0)
        printf("yes\n");
    else if (b == 1)
        printf("yes\n");
    else if (b == 3)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
