#include "stdio.h"

// Function to calculate pi using Leibniz approximation formula
long double leibniz(long long int n)
{
    long double sum = 0;
    int sign = 1;
    for (long long int i = 1; i < n; i += 2)
    {
        if (sign)
        {
            sum += 1.0 / i;
            sign = 0;
        }
        else
        {
            sum -= 1.0 / i;
            sign = 1;
        }
    }
    return sum;
}

// Main driver code
int main()
{
    int n = 100000;
    for (long long int i = 0; i <= n; i += 1000)
    {
        long double ans = leibniz(i);
        printf("PI for the %lld th term = %.12Lf\n", i, ans * 4);
    }
}