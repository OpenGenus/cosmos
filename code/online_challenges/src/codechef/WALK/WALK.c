#include <stdio.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int n;
        scanf("%d", & n);
        int i, v = 0;
        for (i = 0; i < n; ++i) 
        {
            int a;
            scanf("%d", & a);
            if ((i + a) > v)
                v = a + i;
        }
        printf("%d\n", v);
    }
    return 0;
}
