//Part of Cosmos by OpenGenus Foundation
#include<stdio.h>

//loop
int sumOfDigits(int number)
{
    int sum = 0;
    while(number != 0)
    {
        sum += (number % 10);
        number /= 10;
    }
    return sum;
}

//recursive
int recurSumOfDigits(int number)
{
    if(number == 0)
        return 0;
    return ((number%10) + sumOfDigits(number/10));
}

int main()
{
    int num;
    printf("Enter number to be summed: ");
    scanf("%d", &num);
    printf("Digits summed: %d\n", sumOfDigits(num));
    printf("Digits summed: %d", recurSumOfDigits(num));
}
