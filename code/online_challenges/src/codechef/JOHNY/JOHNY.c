#include <stdio.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int i, j;
        int n;
        scanf("%d", & n);
        long long int a[100];
        long long int pj = 0;
        for (i = 0; i < n; ++i) 
        {
            scanf("%lld", & a[i]);
        }
        int x;
        scanf("%d", & x);
        int cr = a[x - 1];
        for (i = 0; i < n - 1; ++i) 
        {
            for (j = 0; j < n - 1; ++j) 
            {
                if (a[j] > a[j + 1]) 
                {
                    pj = a[j + 1];
                    a[j + 1] = a[j];
                    a[j] = pj;
                }
            }
        }
        for (i = 0; i < n; ++i) 
        {
            if (a[i] == cr) 
            {
                printf("%d\n", i + 1);
            }
        }

    }
    return 0;
}
