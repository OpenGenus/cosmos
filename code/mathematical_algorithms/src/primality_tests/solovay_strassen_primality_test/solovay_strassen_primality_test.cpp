// C++ program to implement Solovay-Strassen
// Primality Test
#include <iostream>
using namespace std;

// modulo function to perform binary exponentiation
long long modulo(long long base, long long exponent,
                 long long mod)
{
    long long x = 1;
    long long y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;

        y = (y * y) % mod;
        exponent = exponent / 2;
    }

    return x % mod;
}

// To calculate Jacobian symbol of a given number
int calculateJacobian(long long a, long long n)
{
    if (!a)
        return 0; // (0/n) = 0

    int ans = 1;
    if (a < 0)
    {
        a = -a; // (a/n) = (-a/n)*(-1/n)
        if (n % 4 == 3)
            ans = -ans; // (-1/n) = -1 if n = 3 (mod 4)
    }

    if (a == 1)
        return ans; // (1/n) = 1

    while (a)
    {
        if (a < 0)
        {
            a = -a;// (a/n) = (-a/n)*(-1/n)
            if (n % 4 == 3)
                ans = -ans; // (-1/n) = -1 if n = 3 (mod 4)
        }

        while (a % 2 == 0)
        {
            a = a / 2;
            if (n % 8 == 3 || n % 8 == 5)
                ans = -ans;

        }

        swap(a, n);

        if (a % 4 == 3 && n % 4 == 3)
            ans = -ans;
        a = a % n;

        if (a > n / 2)
            a = a - n;

    }

    if (n == 1)
        return ans;

    return 0;
}

// To perform the Solovay-Strassen Primality Test
bool solovoyStrassen(long long p, int iterations)
{
    if (p < 2)
        return false;
    if (p != 2 && p % 2 == 0)
        return false;

    for (int i = 0; i < iterations; i++)
    {
        // Generate a random number a
        long long a = rand() % (p - 1) + 1;
        long long jacobian = (p + calculateJacobian(a, p)) % p;
        long long mod = modulo(a, (p - 1) / 2, p);

        if (!jacobian || mod != jacobian)
            return false;
    }
    return true;
}

// Driver Code
int main()
{
    int iterations = 50;
    long long num1 = 15;
    long long num2 = 13;

    if (solovoyStrassen(num1, iterations))
        printf("%lld is prime\n", num1);
    else
        printf("%lld is composite\n", num1);

    if (solovoyStrassen(num2, iterations))
        printf("%lld is prime\n", num2);
    else
        printf("%lld is composite\n", num2);

    return 0;
}
