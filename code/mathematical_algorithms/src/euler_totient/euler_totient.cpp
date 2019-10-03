#include <iostream>
using namespace std;
long long phi(long long n)
{
    long long result = n;   // Initialize result as n

    // Consider all prime factors of n and subtract their
    // multiples from result
    for (long long p = 2; p * p <= n; ++p)
        // Check if p is a prime factor.
        if (n % p == 0)
        {
            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
    return result;
}

int main()
{
    long long n;
    cout << "Enter the value of N\n";
    cin >> n;
    for (long long i = 1; i <= n; i++)
        printf("phi(%lld) = %lld\n", i, phi(i));
    return 0;
}
