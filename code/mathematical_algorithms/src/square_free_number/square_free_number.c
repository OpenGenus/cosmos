//Program to check whether a number is square_free or not
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isSquareFree(int n)
{
    if(n % 2 == 0)
        n /= 2;
    if(n % 2 == 0)
        return 0;
    int i;
    for(i = 3; i <= sqrt(n); i += 2)
    {
        if(n % i == 0)
        {
            n /= i;
            if(n % i == 0)
                return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    if(isSquareFree(n))
        printf("%d is square free number",n);
    else
        printf("%d is not a square free number",n);
    return 0;
}
