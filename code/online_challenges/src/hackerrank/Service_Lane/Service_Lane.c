#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() 
{
    int n, t;
    scanf("%d %d", & n, & t);
    int a[n];
    int i;
    for (i = 0; i < n; ++i)
        scanf("%d", & a[i]);
    while (t--) 
    {
        int min = INT_MAX;
        int a1, b;
        scanf("%d %d", & a1, & b);
        for (i = a1; i <= b; ++i) 
        {
            if (min > a[i])
                min = a[i];
        }
        printf("%d\n", min);
    }
}
