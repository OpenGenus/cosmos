#include <stdio.h>

int main() 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int n;
        scanf("%d", & n);
        int arr[n];
        int i, j;
        for (i = 0; i < n; ++i)
            scanf("%d", & arr[i]);
        int temp = 0;
        for (i = 0; i < n; ++i) 
        {
            for (j = i + 1; j < n; ++j) 
            {
                if (arr[i] > arr[j]) 
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        int sum = 0;
        for (i = n - 1; i >= 0; i = i - 4) 
        {
            if (i - 1 >= 0)
                sum += (arr[i] + arr[i - 1]);
            else
                sum += arr[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}
