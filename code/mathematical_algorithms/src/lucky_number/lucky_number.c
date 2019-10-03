/* Part of Cosmos by OpenGenus Foundation */

#include <stdio.h>
#define bool int

bool 
isLucky(int n)
{
    static int counter = 2;

    int next_position = n;
    if (counter > n)
        return (1);
    if (n % counter == 0)
        return (0);

    next_position -= next_position/counter;

    counter++;
    return isLucky(next_position);
}


int 
main()
{
    int x = 5;
    if (isLucky(x))
        printf("%d is a lucky no.", x);
    else
        printf("%d is not a lucky no.", x);
}
