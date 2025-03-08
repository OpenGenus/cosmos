#include <stdio.h>
#define MAX 1000002
int main()
{
    int t;
    long i, arr[MAX], n, p, c[2], val = 0;
    scanf("%d", &t);
    while (t--)
    {
        c[0] = 0;
        c[1] = 0;
        for (i = 0; i < MAX; ++i)
            arr[i] = 0;
        scanf("%d", &n);
        for (i = 0; i < n; ++i)
        {
            scanf("%d", &p);
            if (p % 2 == 0)
                val += c[0];
            else
                val += c[1];
            val -= arr[p];
            val -= arr[p ^ 2];
            c[p % 2]++;
            arr[p]++;
        }
        printf("%ld\n", val);
        val = 0;
    }
    return 0;
}