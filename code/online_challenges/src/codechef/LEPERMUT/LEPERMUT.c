#include <stdio.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int n;
        scanf("%d", & n);
        int a[100];
        int i;
        for (i = 0; i < n; ++i) 
        {
            scanf("%d", & a[i]);
        }
        int c = 0;
        for (i = 0; i < n; ++i) 
        {
            int j;
            for (j = i + 2; j < n; ++j) 
            {
                if (a[i] > a[j]) 
                {
                    c = 1;
                    break;
                }
            }
        }
        if (c == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
