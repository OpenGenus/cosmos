#include <stdio.h>

int main(void) 
{
    long int n;
    scanf("%ld", & n);
    long int i;
    long long int a[n];
    long long int s = 0;
    for (i = 0; i < n; ++i) 
    {
        scanf("%lld", & a[i]);
        s = s + a[i];
    }
    for (i = 1; i <= n; ++i)
        s -= i;
    if (s == 0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
