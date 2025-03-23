/*
input - 123
output - 3
*/


#include <stdio.h>
#include <stdlib.h>

void count(int n)
{
    int a,b=1;
    a=n/10;
    while(a>0)
    {
        b=b+1;
        a=a/10;

    }
    printf("%d",b);
}
int main()
{
    int a;
    scanf("%d",&a);
    count(a);
    return 0;
}

