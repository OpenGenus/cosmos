#include <cmath>
#include <iostream>
#include <vector>

std::vector<long long int> primesUpto(size_t limit) // Function that implements the Sieve of Eratosthenes
{
    std::vector<bool> primesBoolArray(limit, true);
    std::vector<long long int> primesUptoLimit;
    primesBoolArray[0] = primesBoolArray[1] = false;
    size_t sqrtLimit = std::sqrt(limit) + 1;
    for (size_t i = 0; i < sqrtLimit; ++i)
        if (primesBoolArray[i])
            for (size_t j = (2 * i); j < limit; j += i)
                primesBoolArray[j] = false;

    for (size_t i = 0; i < primesBoolArray.size(); ++i)
        if (primesBoolArray[i])
            primesUptoLimit.push_back(i);

    return primesUptoLimit;
}

int main()
{
    std::vector<long long int> primes = primesUpto(1000000); // Arbitrary limit
    std::cout << primes[10000] << "\n";
}
