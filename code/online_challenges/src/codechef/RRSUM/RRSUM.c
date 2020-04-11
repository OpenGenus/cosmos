#include<stdio.h>
#define min(a, b) a > b ? b : a

int main() 
{
    long long int n, m;
    scanf("%lld %lld", & n, & m);
    long long int a[m];
    long long int i;
    for (i = 0; i < m; ++i) 
    {
        scanf("%lld", & a[i]);
    }
    for (i = 0; i < m; ++i) 
    {
        if (a[i] < n + 2 || a[i] > 3 * n)
            printf("0\n");
        else
            printf("%d\n", min((3 * n - a[i] + 1), (a[i] - n - 1)));

    }
}
