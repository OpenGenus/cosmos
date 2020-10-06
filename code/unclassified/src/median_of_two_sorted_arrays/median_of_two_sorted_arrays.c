#include <math.h>
#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i)
    {
        int n;
        scanf("%d", &n);
        int a[n], temp;
        for (int i = 0; i < n; ++i) //input
        {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < n; ++i) //sorting
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (a[i] > a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }

        float median;
        if (n % 2 != 0)
        {
            median = floor(a[(n) / 2]);
        }
        else
        {
            median = floor((a[n / 2] + a[(n - 1) / 2]) / 2);
        }
        printf("%f\n", floor(median));
    }

    return 0;
}
