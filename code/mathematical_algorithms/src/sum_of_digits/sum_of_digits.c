#include <stdio.h>
// Part of Cosmos by OpenGenus Foundation
int 
sumOfDigits(int number)
{
    int sum = 0;
    while(number != 0) {
        sum += (number % 10);
        number /= 10;
    }
    return (sum);
}

int 
main() 
{
    int num;
    printf("Enter number to be summed: ");
    scanf("%d", &num);
    printf("\nThe sum of digits is %d \n",sumOfDigits(num));

    return (0);
}
