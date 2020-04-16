#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n, d;
    scanf("%d %d", & n, & d);
    int a[n];
    int i;
    for (i = 0; i < n; ++i)
        scanf("%d", & a[i]);
    int j, k, c = 0;
    for (i = 0; i < n; ++i) 
    {
        for (j = i + 1; j < n; ++j) 
        {
            if (a[j] - a[i] == d) {
                for (k = j + 1; k < n; ++k) 
                {
                    if (a[k] - a[j] == d) 
                    {
                        ++c;
                    }
                }
            }

        }
    }
    printf("%d", c);
}
