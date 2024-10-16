#include <stdio.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int n, k;
        scanf("%d%d", & n, & k);
        int i, max = 0, c;
        for (i = 2; i <= k; ++i) 
        {
            c = n % i;
            if (c >= max) 
            {
                max = c;
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
