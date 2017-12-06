#include <stdio.h>


//Part of Cosmos by OpenGenus Foundation
int
invert_bit(int n, int number_bit)
{
    n ^= 1 << number_bit;
    return (n);
}

int
main()
{
    int numeric, number_bit, res;
    printf("Enter numeric: ");
    scanf("%d", &numeric);
    printf("Enter number bit: ");
    scanf("%d", &number_bit);
    res = invert_bit(numeric, number_bit);
    printf("Result: %d\n", res);
    return (0);
}
