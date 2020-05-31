#include <stdio.h>
/*
This is a program to represent a number in terms of it's Egyptian fraction. An Egyptian Fraction is a finitet sum of unit fractions. Any 
positive rational number can be represented by sum of unit fractions.
*/
void printEgyptian(int numerator, int denominator)
{
    if (denominator == 0 || numerator == 0)//if numerator is zero, then it cannot be represented as unit fraction. Denominator zero 
        //implies undefined. So we return.
        return;
 
    if (denominator % numerator == 0) {
        printf("1/%d", denominator / numerator);//For example 2/4 becomes 1/2
        return;
    }
 
    if (numerator % denominator == 0) {
        printf("%d", numerator / denominator);
        return;
    }
 
    if (numerator > denominator) {
        printf("%d + ", numerator / denominator);
        printEgyptian(numerator % denominator, denominator);
        return;
    }
 
    int n = (denominator / numerator) + 1;
    printf("1/%d + ", n);//printing the number found
    
    printEgyptian((numerator * n) - denominator, denominator * n);
 }
 
int 
main()
{
    int numerator, denominator;
    printf("Enter numerator ");
    scanf("%d", &numerator);
    printf("Enter denominator ");
    scanf("%d", &denominator);
    printf("Egyptian Fraction Representation of %d/%d is \n", numerator, denominator);
    printEgyptian(numerator, denominator);
    printf("\n");

    return (0);
}
