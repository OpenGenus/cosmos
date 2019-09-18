#include <cmath>
#include <iostream>
#include <vector>

long long int sumOfPrimesUpto(size_t limit) // Function that implements the Sieve of Eratosthenes
{
    std::vector<bool> primesBoolArray(limit, true);
    long long int sum = 0;
    primesBoolArray[0] = primesBoolArray[1] = false;
    for (size_t i = 2; i < limit; ++i)
        if (primesBoolArray[i])
        {
            sum += i;
            for (size_t j = (2 * i); j < limit; j += i)
                primesBoolArray[j] = false;
        }

    return sum;
}

int main()
{
    std::cout << sumOfPrimesUpto(2000000) << "\n";
}
