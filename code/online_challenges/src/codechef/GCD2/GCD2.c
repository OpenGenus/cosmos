#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main() 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        char arr[250];
        int a;
        scanf("%d", & a);
        scanf("%s", arr);
        if (a == 0)
            printf("%s\n", arr);
        else {
            int i, m = 0;
            for (i = 0; i < strlen(arr); ++i) 
            {
                m = (m * 10 + arr[i] - '0') % a;
            }
            int n = gcd(a, m);
            printf("%d\n", n);
        }
    }

    return 0;
}
