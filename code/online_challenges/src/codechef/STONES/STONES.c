#include <stdio.h>
#include <string.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        char s[100], r[100];
        int count = 0, i, j;
        scanf("%s", s);
        scanf("%s", r);
        for (j = 0; j < strlen(r); ++j) 
        {
            for (i = 0; i < strlen(s); ++i) 
            {
                if (s[i] == r[j]) 
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
