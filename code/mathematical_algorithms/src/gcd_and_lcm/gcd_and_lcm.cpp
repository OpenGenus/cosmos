#include <stdio.h>
#include <algorithm>
// Part of Cosmos by OpenGenus Foundation
int gcd(int x, int y)
{
    while (y > 0)
    {
        x %= y;
        std::swap(x, y);
    }
    return x;
}

//should use this recursive approach.
// int gcd(int c,int d)
// {
//     if(d==0)
//         return a;
//     return gcd(d,c%d);
// }

int lcm(int x, int y)
{
    return x / gcd(x, y) * y;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("GCD = %d\n", gcd(a, b));
    printf("LCM = %d", lcm(a, b));
}
