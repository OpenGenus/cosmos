#include <stdio.h>

// Find the nth magic number where n is a positive number
// @param n: the nth number in the sequence to be calculated and returned
// @param fac: factor level. 
// @return: an integer where it is the nth number that can be expressed as a power or sum of the factor level
int 
magicNumber(int n, int fac)
{
    int answer = 0;
    int expo = 1;

    while (n != 0)
    {
        expo = expo * fac;
        if (n & 1)
            answer += expo;
        n = n >> 1; 
    }
    return answer;
}

int 
main()
{
    int n, f;
    printf("n: \n>> ");
    scanf("%d", &n);
    printf("factor: \n>> ");
    scanf("%d", &f);
    
    if (n > 0 && f > 0) {
        printf("The magic number is: %d\n", magicNumber(n, f));
    }
    else {
        printf("n and f must be positive and nonzero.\n");
    }
    return 0;
}