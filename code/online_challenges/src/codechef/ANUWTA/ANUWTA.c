#include <stdio.h>

int main(void) 
{
    long long int t;
    scanf("%lld\n", & t);
    while (t--) 
    {
        long long int n;
        scanf("%lld\n", & n);
        long long int d = (2 * n) + (n * (n - 1) / 2);
        printf("%lld\n", d);
    }
    return 0;
}
