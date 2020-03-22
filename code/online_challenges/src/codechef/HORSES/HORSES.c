#include <stdio.h>

#include<stdlib.h>

int main(void) 
{
    int t, i, j, k, n;
    scanf("%d", & t);
    for (i = 1; i <= t; i++) 
    {
        scanf("%d", & n);
        int s[n];
        for (j = 0; j < n; j++)
            scanf("%d", & s[j]);
        int min = abs(s[0] - s[1]);
        for (k = 0; k < n; k++) {
            for (j = k + 1; j < n; j++) 
            {
                if (abs(s[k] - s[j]) < min)
                    min = abs(s[k] - s[j]);
            }
        }
        printf("%d\n", min);
    }
    return 0;
}
