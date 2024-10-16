#include <stdio.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int n;
        scanf("%d", & n);
        int arr[n], i;
        for (i = 0; i < n; ++i) 
        {
            scanf("%d", & arr[i]);

        }
        int top, c = 0;
        top = arr[0];
        for (i = 0; i < n; ++i) 
        {
            if (top >= arr[i]) 
            {
                c++;
                top = arr[i];
            }
        }
        printf("%d\n", c);
    }
    return 0;
}
