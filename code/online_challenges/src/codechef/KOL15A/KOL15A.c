#include <stdio.h>
#include <string.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    int i;
    for (i = 0; i < t; ++i) 
    {
        char s[1000];
        scanf("%s", s);
        int j, count = 0;
        for (j = 0; s[j]; ++j) 
        {
            if (s[j] > '0' && s[j] <= '9') 
            {
                count += s[j] - '0';
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
