#include <stdio.h>
#include<stdlib.h>

int main(void) 
{
    int t, i, j;
    scanf("%d", & t);
    for (i = 1; i <= t; ++i) 
    {
        int n;
        scanf("%d", & n);
        int s[n];
        for (j = 0; j < n; ++j)
            scanf("%d", & s[j]);
        int min = abs(s[0] - s[1]);
        for (j = 0; j < n; ++j) 
        {
        	int k;
            for (k = j + 1; k < n; ++k) 
            {
                if (abs(s[j] - s[k]) < min)
                    min = abs(s[j] - s[k]);
            }
        }
        printf("%d\n", min);
    }
    return 0;
}
