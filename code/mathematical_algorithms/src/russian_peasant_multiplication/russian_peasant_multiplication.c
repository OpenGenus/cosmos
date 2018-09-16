#include <stdio.h>

unsigned int 
russianPeasant(unsigned int a, unsigned int b)
{
    int res = 0; 

    while (b > 0) {
        if (b & 1)
        	res += a;

        a = a << 1;
        b = b >> 1;
    }

     return (res);
}

int 
main()
{
    printf("%u\n", russianPeasant(18, 1));
    printf("%u\n", russianPeasant(20, 12));

    return (0);
}
