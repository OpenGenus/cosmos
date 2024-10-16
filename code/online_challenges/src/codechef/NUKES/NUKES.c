#include <stdio.h>

int main(void) 
{
    int n, max, k;
    scanf("%d %d %d", & n, & max, & k);
    int i = 0;
    int l = max + 1;
    while (i < k) 
    {
        printf("%d ", n % l);
        n = n / l;
        ++i;
    }
    printf("\n");
    return 0;
}
