#include<stdio.h>
#include<math.h>

int main() 
{
    int t, i;
    scanf("%d", & t);
    while (t--) 
    {
        int n, a, b;
        scanf("%d%d%d", & n, & a, & b);
        int count1 = 0, count2 = 0, count = 0;
        for (i = 0; i < n; ++i) 
        {
            if (a & (1 << i))
                count1++;
            if (b & (1 << i))
                count2++;
        }
        count = count1 + count2;
        if (count == n) 
        {
            int result = pow(2, n) - 1;
            printf("%d\n", result);
        } 
        else if (count < n) 
        {
            count = n - count;
            int result = pow(2, n) - pow(2, count);
            printf("%d\n", result);
        } 
        else if 
        (count > n) 
        {
            count = count - n;
            int result = pow(2, n) - pow(2, count);
            printf("%d\n", result);
        }
    }
    return 0;
}
