/* Fibonacci Series implemented using Memoization */
#include <iostream>

long long fibonacci (int n)
{
    static long long fib[100] = {}; // initialises the array with all elements as 0
    fib[1] = 0;
    fib[2] = 1;

    if (n == 1 || n == 2)
        return fib[n];
    else if (fib[n] != 0)
        return fib[n];
    else
    {
        fib[n] = fibonacci (n - 1) + fibonacci (n - 2);
        return fib[n];
    }
}

int main ()
{
    int n;
    std::cout << "Enter number of terms: ";
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cout << fibonacci (i) << std::endl;
}
