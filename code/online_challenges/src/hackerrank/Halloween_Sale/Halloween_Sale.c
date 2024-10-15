#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int p, d, m, s;
    scanf("%d %d %d %d", & p, & d, & m, & s);
    int sum = p;
    int c = 1;
    while (s >= sum) 
    {
        if ((p - d) <= m) 
        {
            sum += m;
            ++c;
            p -= d;
        } else {
            p -= d;
            sum += p;
            ++c;
        }
    }
    if (sum > s)
        printf("%d", c - 1);
    else
        printf("%d", c);
}
