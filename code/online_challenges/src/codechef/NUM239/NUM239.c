#include <stdio.h>
#include<stdlib.h>

int main(void)
{
    int t;
    scanf("%d", & t);
    if (t >= 1 && t <= 100)
        while (t--)
        {
            long int l, r;
            scanf("%ld %ld", & l, & r);
            long int i, count = 0;
            if (l >= 1 && r >= 1 && l <= 100000 && r <= 100000 && l <= r)
            {
                for (int i = l; i <= r; ++i)
                {

                    long int ldig = i % 10;
                    if (ldig == 2 || ldig == 3 || ldig == 9)
                        count++;
                }
                printf("%ld\n", count);
            }
        }
    return 0;
}
