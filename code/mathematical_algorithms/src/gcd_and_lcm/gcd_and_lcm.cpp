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
