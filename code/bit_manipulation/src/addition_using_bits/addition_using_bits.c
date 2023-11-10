/*
Problem Statement :
Add two numbers using bitwise operators
(i.e without using arithmetic operators)
*/

#include <stdio.h>
#include <limits.h>

// Function to add two numbers using bitwise operators
int bitwiseAddition(int n, int m)
{
    while (m != 0)
    {
        int carry = n & m;
        n = n ^ m;
        m = carry << 1;

        // Check for overflow (positive to negative or vice versa)
        if ((n < 0 && m > 0) || (n > 0 && m < 0))
        {
            fprintf(stderr, "Overflow detected. Cannot add numbers.\n");
            return INT_MAX; // Return the maximum possible value
        }
    }
    return n;
}

// recursive function
int bitwiseAdditionRecursive(int n, int m)
{
    if (m == 0)
        return n;
    else
    {
        int carry = n & m;
        return bitwiseAdditionRecursive(n ^ m, carry << 1);
    }
}

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    if (scanf("%d %d", &a, &b) != 2)
    {
        fprintf(stderr, "Invalid input. Please enter two integers.\n");
        return 1; // Exit with an error code
    }

    int result = bitwiseAddition(a, b);
    if (result == INT_MAX)
    {
        return 1; // Exit with an error code
    }

    printf("\nBitwise addition using iterative function : %d", bitwiseAddition(a, b));
    printf("\nBitwise addition using recursive function : %d", bitwiseAdditionRecursive(a, b));
    return 0;
}

/*
Enter two numbers : 3 5

Bitwise addition using iterative function : 8
Bitwise addition using recursive function : 8
*/
