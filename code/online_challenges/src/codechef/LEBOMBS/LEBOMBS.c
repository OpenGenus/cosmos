#include <stdio.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int n;
        scanf("%d", & n);
        char s[n];
        scanf("%s", s);
        s[-1] = '0';
        s[n] = '0';
        int i, k = 0;
        for (i = 0; i < n; ++i) 
        {
            if (s[i] == '0' && s[i + 1] != '1' && s[i - 1] != '1')
                k += 1;
        }
        printf("%d\n", k);
    }
    return 0;
}
