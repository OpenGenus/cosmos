#include <stdio.h>

int main() 
{
    int t;
    scanf("%d", & t);
    while (t != 0) 
    {
        int i;
        int n, m;
        scanf("%d%d", & n, & m);
        int a[n];
        for (i = 1; i <= n; ++i)
            a[i] = 1;
        for (i = 1; i <= m; ++i) 
        {
            int o;
            scanf("%d", & o);
            a[o] = 0;
        }
        for (i = 1; i <= n; ++i) 
        {
            if (a[i] != 0) 
            {
                printf("%d ", i);
                a[i] = 0;
                while (a[i] == 0)
                    i++;
            }
        }
        printf("\n");
        for (i = 1; i <= n; ++i) 
        {
            if (a[i] != 0) 
            {
                printf("%d ", i);

            }
        }

        t--;
        printf("\n");
    }
    return 0;
}
