#include <stdio.h>

int
main(void)
{
    int sum, i;
    
    for (i = 0; i < 1000; ++i)
        sum += (i % 3 == 0) || (i % 5 == 0) ? i : 0;
    
    printf("%d\n", sum);
}