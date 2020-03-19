#include <stdio.h>

#include <stdlib.h>

main() 
{
    long t, n, s = 1, sum = 0, k;
    scanf("%ld", & t);
    while (t--) 
    {
        scanf("%ld", & n);
        while (1) 
        {
            s = s * 5;
            if (s > n)
                break;
            else 
            {
                k = n / s;
                sum = sum + k;
            }
        }
        printf("%ld\n", sum);
        sum = 0;
        s = 1;
    }
}