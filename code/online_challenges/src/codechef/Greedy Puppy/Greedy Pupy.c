#include <stdio.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int n, l, k, c, max = 0, i;
        scanf("%d%d", & n, & k);
        for (int i = 2; i <= k; i++) 
        {
            c = n % i;
            if (c >= max) 
            {
                max =a c;
            }
        }
        printf("%d\n", max);
    }
    return 0;
}