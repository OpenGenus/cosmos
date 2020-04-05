#include <stdio.h>

int main() 
{
    int n, i;
    scanf("%d", & n);
    int a[1001];
    a[0] = 0;
    int b[1001];
    for (i = 1; i <= n; ++i) 
    {
        scanf("%d", & a[i]);
        b[i] = 0;
    }
    int arr[5000];
    int c = 0, count = 0;
    i = 1;
    while (i <= n) 
    {
        arr[++c] = i;
        if (b[i] == 1) 
        {
            arr[++c] = 0;
            ++count;
            while (i <= n && b[i] == 1)
                ++i;

        } 
        else 
        {
            b[i] = 1;
            i = a[i];
        }
    }
    printf("%d", count);
    for (i = 0; i < c; ++i) 
    {
        if (arr[i] == 0)
            printf("\n");
        else
            printf("%d ", arr[i]);
    }
    return 0;
}
