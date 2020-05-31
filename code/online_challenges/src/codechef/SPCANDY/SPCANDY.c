#include <stdio.h>

int main(void) 
{
    long long int t;
    scanf("%lld", & t);
    while (t--) 
    {
        long long int n, k;
        scanf("%lld %lld", & n, & k);
        if (k != 0)
            printf("%lld %lld\n", n / k, n % k);
        else
            printf("0 %lld\n", n);

    }
    return 0;
}
