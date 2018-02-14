#include <stdio.h>

int
main(void)
{
    long long int n = 600851475143;
    long long int h = 0;
    long long int c = 2;
    while (n != 1) {
        if ((n % c == 0) && (c > h)) {
            h = c;
            n /= c;
        }
        ++c;
    }
    
    printf("%lld\n", h);
}