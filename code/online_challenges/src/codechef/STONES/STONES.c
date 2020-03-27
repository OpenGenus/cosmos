#include <stdio.h>
#include <string.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        char s[100], r[100];
        int count = 0;
        scanf("%s", s);
        scanf("%s", r);
        int l = strlen(r);
        int i;
        for (i = 0; < l; ++i) 
        {
            int j;
            for (j = 0; j < l; ++j) 
            {
                if (s[j] == r[i]) 
                {
                    ++count;
                    break;
                }

            }
        }
        printf("%d\n", count);
    }
    return 0;
}
