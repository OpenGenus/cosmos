#include <stdio.h>

int main()
{
    int n, i, jump = 0;
    scanf ("%d", &n);
    int c[n];
    for (i=0;i<n;i++)
    {
        scanf ("%d", &c[i]);
    }
    for (i=0;i<n;i++)
    {
        if (i+2 < n && !c[i+2])
        {
            jump++;
            i++;
        }
        else if (i+1 < n && !c[i+1])
        {
            jump++;
        }
    }
    printf ("%d", jump);
    return 0;
}
