#include<stdio.h>

int main() 
{
    int t;
    scanf("%d", & t);
    int T[t];
    int i, j;
    for (i = 0; i < t; ++i) 
    {
        int n;
        scanf("%d", & n);
        int A[n];
        int min = 32767;
        for (j = 0; j < n; ++j) 
        {
            scanf("%d", & A[j]);
            if (A[j] < min) 
            {
                min = A[j];
            }
        }
        int count = 0;
        for (j = 0; j < n; ++j) 
        {
            count += (A[j] - min);
        }
        T[i] = count
    }

    for (i = 0; i < t; ++i) 
    {
        printf("%d\n", T[i]);
    }
    return 0;
}
