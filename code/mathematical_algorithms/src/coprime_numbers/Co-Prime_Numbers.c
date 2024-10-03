#include <stdio.h>

// Function to calculate the GCD of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to check if two numbers are coprime
int areCoprime(int num1, int num2) {
    return (gcd(num1, num2) == 1);
}

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    if (areCoprime(num1, num2)) {
        printf("%d and %d are coprime.\n", num1, num2);
    } else {
        printf("%d and %d are not coprime.\n", num1, num2);
    }

    return 0;
}
