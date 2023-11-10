#include<stdio.h>

int main() 
{
    int n1, n2, n3;
    scanf("%ld %ld %ld", & n1, & n2, & n3);
    int n[1000000] = {0};
    int i;
    for (i = 0; i < n1; ++i) 
    {
        int x;
        scanf("%ld", & x);
        ++n[x];
    }
    for (i = 0; i < n2; ++i) 
    {
        int x;
        scanf("%ld", & x);
        ++n[x];
    }
    for (i = 0; i < n3; ++i) 
    {
        int x;
        scanf("%ld", & x);
        ++n[x];
    }
    int count = 0;
    for (i = 0; i < 1000000; ++i) 
    {
        if (n[i] > 1)
            ++count;
    }
    printf("%ld\n", count);
    for (i = 0; i < 1000000; ++i) 
    {
        if (n[i] > 1)
            printf("%ld\n", i);
    }
    return 0;
}
