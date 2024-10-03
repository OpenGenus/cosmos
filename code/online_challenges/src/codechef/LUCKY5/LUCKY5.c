#include <stdio.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        char no[100000];
        scanf("%s", no);
        int i, count = 0, z = 0;
        for (i = 0; no[i] != '\0'; ++i) 
        {
            ++z;
            if ((no[i] == '7') || (no[i] == '4'))
                ++count;
        }
        printf("%d\n", z - count);
    }
    return 0;
}
