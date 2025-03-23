#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n, m;
    scanf("%d %d", & n, & m);
    int a[m];
    int i;
    for (i = 0; i < m; ++i)
        scanf("%d", & a[i]);
    int max1 = 0;
    for (i = 0; i < n; ++i) 
    {
        int min = 99999999, j;
        for (j = 0; j < m; ++j) 
        {
            int t = abs(i - a[j]);
            if (min > t)
                min = t;
        }
        if (max1 < min)
            max1 = min;
    }
    printf("%d", max1);
}
