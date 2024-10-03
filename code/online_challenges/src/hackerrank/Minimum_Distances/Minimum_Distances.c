#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", & n);
    int a[n];
    int i;
    for (i = 0; i < n; ++i)
        scanf("%d", & a[i]);
    int temp = 0, num, k;
    for (i = 0; i < n - 1; ++i) 
    {
        int j;
        for (j = i + 1; j < n; ++j) 
        {
            if (a[i] == a[j]) 
            {
                k = j - i;
                if (temp == 0) 
                {
                    num = k;
                    temp = 1;
                }
            }
            if (num > k)
                num = k;
        }
    }
    if (temp == 0)
        printf("-1\n");
    else
        printf("%d\n", num);
    return 0;
}
