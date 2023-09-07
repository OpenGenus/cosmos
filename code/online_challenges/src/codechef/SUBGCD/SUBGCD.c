#include <stdio.h>

#include <stdlib.h>

int main() 
{
    int r;
    scanf("%d", & r);
    int x, m = 0;
    while (m < r) 
    {
        x = 0;
        int n;
        scanf("%d", & n);
        if (n < 2 || n > 100000) 
        {
            m++;
            continue;
        }
        int a[n], i;
        for (i = 0; i < n; i++) 
        {
            scanf("%d", & a[i]);
            if (a[i] < 1 || a[i] > 100000) 
            {
                x++;
            }
        }
        if (x > 0) 
        {
            m++;
            continue;
        }
        int max = 0;
        for (i = 0; i < n; i++)
            if (a[i] > max)
                max = a[i];
        int min = max;
        for (i = 0; i < n; i++)
            if (a[i] < min && a[i] != 1) 
            {
                min = a[i];
            }
        int s = 0;
        for (i = 0; i < n; i++) 
        {
            if (a[i] % min == 0)
                s++;
        }
        if (s == n)
            printf("%d\n", -1);
        else
            printf("%d\n", n);
        m++;
    }
    return 0;
}
