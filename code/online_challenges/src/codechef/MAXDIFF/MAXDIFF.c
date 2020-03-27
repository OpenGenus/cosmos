#include <stdio.h>

int main() 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int i, j, n, k;
        scanf("%d %d", & n, & k);
        int a[n];
        for (i = 0; i < n; ++i)
            scanf("%d", & a[i]);
        for (i = 0; i < n - 1; ++i) 
        {
            for (j = 0; j < n - i - 1; ++j) 
            {
                if (a[j] > a[j + 1]) 
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        int ch = 0, sn = 0;
        if (n - k > k) 
        {
            for (i = 0; i < k; ++i)
                sn += a[i];
            for (i = k; i < n; ++i)
                ch += a[i];
        } else 
        {
            for (i = 0; i < n - k; ++i)
                sn += a[i];
            for (i = n - k; i < n; ++i)
                ch += a[i];
        }
        printf("%d\n", ch - sn);
    }
    return 0;
}
