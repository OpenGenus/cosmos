#include <stdio.h>

void 
printEgyptian(int numerator, int denominator)
{
    if (denominator == 0 || numerator == 0)
        return;
 
    if (denominator % numerator == 0) {
        printf("1/%d", denominator / numerator);
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
    printf("1/%d + ", n);
    
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