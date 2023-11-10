#include <stdio.h>

int main() 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        long long int n, i;
        scanf("%lld", & n);
        long long int a[n];
        for (i = 0; i < n; ++i) 
        {
            scanf("%lld", & a[i]);
        }
        long long int min = a[0];
        for (i = 0; i < n; ++i) 
        {
            if (a[i] < min) 
            {
                min = a[i];
            }
        }
        printf("%lld\n", min * (n - 1));
    }
    return 0;
}
