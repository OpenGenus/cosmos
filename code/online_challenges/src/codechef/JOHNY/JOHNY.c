#include <stdio.h>

int main(void) 
{
    int t, n, x, cr, k, j;
    scanf("%d", & t);
    while (t--) 
    {
        scanf("%d", & n);
        long long int a[100], pj = 0;
        for (k = 0; k < n; k++) 
        {
            scanf("%lld", & a[k]);
        }
        scanf("%d", & x);
        cr = a[x - 1];
        for (k = 0; k < n - 1; k++) 
        {
            for (j = 0; j < n - 1; j++) 
            {
                if (a[j] > a[j + 1]) 
                {
                    pj = a[j + 1];
                    a[j + 1] = a[j];
                    a[j] = pj;
                }
            }
        }
        for (k = 0; k < n; k++) 
        {
            if (a[k] == cr) 
            {
                printf("%d\n", k + 1);
            }
        }

    }
    return 0;
}
