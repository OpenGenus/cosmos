#include<stdio.h>

int main() 
{
    int t;
    scanf("%d", & t);
    while (t > 0) 
    {
        int n, c, q;
        scanf("%d %d %d", & n, & c, & q);
        int cup = c;
        while (q > 0) 
        {
            int a, b;
            scanf("%d %d", & a, & b);
            if (a <= cup && b >= cup) 
            {
                int r = cup - a;
                cup = b - r;
            }
            q--;
        }
        printf("%d\n", cup);
        t--;
    }
    return 0;
}
