/*
Problem Statement : 
Add two numbers using bitwise operators
(i.e without using arithmetic operators)
*/

#include <stdio.h>

// iterative function
int bitwiseAddition(int n, int m)
{
    while (m != 0)
    {
        int carry = n & m;  
        n = n ^ m;      
        m = carry << 1; 
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
    scanf("%d %d", &a, &b);
    
    printf("\nBitwise addition using iterative function : %d", bitwiseAddition(a, b));
    printf("\nBitwise addition using recursive function : %d", bitwiseAdditionRecursive(a, b));
    return 0;
}

/*
Enter two numbers : 3 5

Bitwise addition using iterative function : 8
Bitwise addition using recursive function : 8
*/
