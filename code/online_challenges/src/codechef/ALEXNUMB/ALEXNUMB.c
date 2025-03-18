#include <stdio.h>

int main(void) 
{
    long long int i, t;
    scanf("%lld", & t);
    for (i = 0; i < t; ++i) 
    {
        long long int n;
        scanf("%lld", & n);
        long long int a;
        long long int j;
        for (j = 0; j < n; ++j)
            scanf("%lld", & a);
        a = (n * n) - n;
        a = a / 2;
        printf("%lld\n", a);
    }
    return 0;
}
