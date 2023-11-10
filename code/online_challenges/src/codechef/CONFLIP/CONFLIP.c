#include<stdio.h>

int main() 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int u;
        scanf("%d", & u);
        while (u--) 
        {
            int i, n, q;
            scanf("%d%d%d", & i, & n, & q);
            if (i == q) 
            {
                printf("%d\n", n / 2);
            } else 
            {
                printf("%d\n", n / 2 + n % 2);
            }
        }
    }
}
