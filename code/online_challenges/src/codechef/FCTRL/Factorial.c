#include <stdio.h>
#include <stdlib.h>

int main() 
{
    long t;
    scanf("%ld", & t);
    while (t--) 
    {
        long n;
        scanf("%ld", & n);
        long s = 1, sum = 0;
        while (1) 
        {
            s *= 5;
            if (s > n)
                break;
            else 
            {
                long k = n / s;
                sum += k;
            }
        }
        printf("%ld\n", sum);
    }
}
