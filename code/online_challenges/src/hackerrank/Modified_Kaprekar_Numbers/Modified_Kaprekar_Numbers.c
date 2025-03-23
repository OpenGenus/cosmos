#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int p, q, c = 0;
    scanf("%d", & p);
    scanf("%d", & q);
    int count = 0;
    long long int  i, k;
    for (long long i = p; i <= q; i++) 
    {
        long long square = i * i;
        long long square_copy = square;
        int digCount = 0;
        while (square_copy) 
        {
            square_copy /= 10;
            digCount++;
        }
        digCount += digCount % 2;

        long long power = 10;
        for (long long k = 1; k < digCount / 2; ++k) 
        {
            power *= 10;
        }
        long long r = square % power;
        long long l = square / power;
        if (r + l == i) 
        {
            printf("%lld ", i);
            ++count;
        }

    }

    if (count == 0) 
    {
        printf("INVALID RANGE");
    }
    return 0;
}
