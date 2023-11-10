#include <stdio.h>

int main() 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int m, n, i, j;
        scanf("%d %d", & n, & m);
        int b[m + 1];
        for (i = 1; i <= m; ++i)
            b[i] = 0;
        b[0] = 1;
        for (i = 0; i < n; ++i) 
        {
            int k;
            scanf("%d", & k);
            for (j = m - k; j >= 0; --j) 
            {
                if (b[j] > 0)
                    b[j + k] = 1;
            }
        }
        if (b[m] > 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
