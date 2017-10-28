// Part of Cosmos by OpenGenus Foundation

#include <stdio.h>

int factorial(int val)
{
    if (val == 0) {
        return 1;
    }
    return val * factorial(val - 1);
}

int main()
{
    int val = 5;
    printf("Factorial for %d: %d\n", val, factorial(5));
    return 0;
}
