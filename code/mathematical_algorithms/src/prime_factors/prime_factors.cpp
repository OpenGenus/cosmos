// Part of Cosmos by OpenGenus Foundation
#include <stdio.h>
void prime_factors(int);
int main()
{
    int n;
    scanf("%d", &n);
    prime_factors(n);
    return 0;
}
void prime_factors(int n)
{
    for (int d = 2; d * d <= n; d++) // take all divisors till sqrt(n)
    {
        if (n % d == 0)
            printf("%d ", d); //this is surely prime,if it weren't, an earlier divisor of it would've nuked it from n
        while (n % d == 0)
            n /= d;
        //nuke the prime divisor from n
    }
    if (n > 1)
        printf("%d", n);
    //we nuked all prime divisors,so if n is not one,then it's prime
}
