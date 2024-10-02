#include <stdio.h>

// Function to calculate the GCD of two numbers using the Euclidean algorithm
int gcd(int a, int b) {
   
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int num1, num2;

    // Input two numbers from the user
    printf("Enter First number:");
    scanf("%d", &num1);
    printf("Enter Second number:");
    scanf("%d" , &num2);

    // Calculate the GCD of the two numbers
    int gcd_result = gcd(num1, num2);

    // Check if the GCD is 1 (co-prime) or not
    if (gcd_result == 1) 
    {
        printf("%d and %d are co-prime.\n", num1, num2);
    } 
    else 
    {
        printf("%d and %d are not co-prime.\n", num1, num2);
    }

    return 0;
}


