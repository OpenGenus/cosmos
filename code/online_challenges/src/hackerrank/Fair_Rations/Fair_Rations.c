#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", & n);
    int a[n], sum = 0, i;
    for (i = 0; i < n; ++i) 
    {
        scanf("%d", & a[i]);
        sum += a[i];
    }
    int c = 0;
    if (sum % 2 == 0) 
    {
        for (i = 0; i < n; ++i) 
        {
            if (a[i] % 2 != 0) 
            {
                a[i] += 1;
                a[i + 1] += 1;
                c += 2;
            }
        }
        printf("%d", c);
    } 
    else
    {
        printf("NO");
    }
}
