#include <stdio.h>

long long int gcd(long long int a, long long int b) 
{
    if (b == 0) 
    {
        return a;
    }
    return gcd(b, a % b);
}

int main(void) 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        long long int n;
        scanf("%lld", & n);
        long long int a;
        scanf("%lld", & a);
        if (n == 1) 
        {
            printf("%lld\n", a);
            continue;
        }
        while (--n) 
        {
            long long int b;
            scanf("%lld", & b);
            a = a < b ? gcd(a, b) : gcd(b, a);
        }
        printf("%lld\n", a);
    }
    return 0;
}
