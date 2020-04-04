#include <stdio.h>

#include <string.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        char m[30000], w[30000];
        scanf("%s %s", m, w);
        int l = strlen(m);
        int s = 0, i, j, p, z = 0;
        int k = strlen(w);
        if (l < k) {
            for (i = 0; i < l; ++i) 
            {
                for (j = z; j < k; ++j) 
                {
                    if (m[i] == w[j]) 
                    {
                        s += 1;
                        z = j + 1;
                        break;
                    }
                }
            }
            if (s == l)
                printf("YES\n");
            else
                printf("NO\n");
        } 
        else 
        {
            for (i = 0; i < k; ++i) 
            {
                for (j = z; j < l; ++j) 
                {
                    if (m[j] == w[i]) 
                    {
                        s += 1;
                        z = j + 1;
                        break;
                    }
                }
            }
            if (s == k)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
