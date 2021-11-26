/*

// mathematical algorithms | armstrong numbers | armstrong numbers | C
// Part of Cosmos by OpenGenus Foundation

*/


/* Part of Cosmos by OpenGenus Foundation */
#include <stdio.h>

int 
main()
{
    int number, originalNumber, remainder, result = 0;

    printf("Enter a three digit integer: ");
    scanf("%d", &number);

    originalNumber = number;

    while (originalNumber != 0) {
        remainder = originalNumber % 10;
        result += remainder * remainder * remainder;
        originalNumber /= 10;
    }

    if (result == number)
        printf("%d is an Armstrong number.", number);
    
    else
        printf("%d is not an Armstrong number.", number);

    return (0);
}
