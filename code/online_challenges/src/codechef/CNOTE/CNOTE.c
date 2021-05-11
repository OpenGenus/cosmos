#include<stdio.h>

int main() 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int x, y, k, n;
        scanf("%d%d%d%d", & x, & y, & k, & n);
        int p[n], c[n], flag = 0, i;
        for (i = 0; i < n; ++i) 
        {
            scanf("%d%d", & p[i], & c[i]);
            if (p[i] >= x - y && c[i] <= k) 
            {
                ++flag;
            }
        }
        if (flag == 0) 
        {
            printf("UnluckyChef\n");
        } else 
        {
            printf("LuckyChef\n");
        }

    }
}
