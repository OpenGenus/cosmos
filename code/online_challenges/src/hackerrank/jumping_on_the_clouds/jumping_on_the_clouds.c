#include <stdio.h>

int main()
{
    int n, i;
    scanf ("%d", &n);
    int c[n];
    for (i=0;i<n;++i)
    {
        scanf ("%d", &c[i]);
    }
    int jump = 0;
    for (i=0;i<n;++i)
    {
        if (i+2 < n && !c[i+2])
        {
            ++jump;
            ++i;
        }
        else if (i+1 < n && !c[i+1])
        {
            ++jump;
        }
    }
    printf ("%d", jump);
    return 0;
}
