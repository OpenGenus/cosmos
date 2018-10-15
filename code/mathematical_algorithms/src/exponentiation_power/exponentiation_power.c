#include <stdio.h>
// Part of Cosmos by OpenGenus Foundation
int 
power(int num, int exp)
{
    if (exp == 0)
        return (1);
    else if (exp == 1)
        return (num);

    int result = power(num, exp / 2);
        result *= result;
    if (exp % 2 == 1)
        result *= num;
    return (result);
}

int 
main()
{
    int num, exp;

    printf("Input Number \n");
    scanf("%d", &num);
    printf("Input Exponent \n");
    scanf("%d", &exp);

    printf("The result is %d \n", power(num, exp));

    return (0);
}
