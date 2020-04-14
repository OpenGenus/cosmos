#include <stdio.h>
#include <math.h>

int main() 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int m, n;
        scanf("%d %d", & m, & n);
        int i;
        for (i = m; i <= n; ++i)
            if (isPrime(i))
                printf("%d\n", i);
        printf("\n");
    }
}

int isPrime(int n) 
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    int i;
    for (i = 2; i < sqrt(n) + 1; ++i)
        if (n % i == 0)
            return 0;
    return 1;
}
