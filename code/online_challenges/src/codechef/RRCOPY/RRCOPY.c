#include <stdio.h>
#include <string.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int n, h[1000000] = {0};
        scanf("%d", & n);
        int count = 0;
        while (n--) 
        {
            int temp;
            scanf("%d", & temp);
            if (h[temp] == 0) 
            {
                count++;
                h[temp]++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
