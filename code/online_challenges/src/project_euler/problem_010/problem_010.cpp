#include <cmath>
#include <iostream>
#include <vector>

long long int sumOfPrimesUpto(size_t limit) // Function that implements the Sieve of Eratosthenes
{
    std::vector<bool> primesBoolArray(limit, true);
    long long int sum;
    primesBoolArray[0] = primesBoolArray[1] = false;
    size_t sqrtLimit = std::sqrt(limit) + 1;
    for (size_t i = 0; i < sqrtLimit; ++i)
        if (primesBoolArray[i])
            for (size_t j = (2 * i); j < limit; j += i)
                primesBoolArray[j] = false;

    for (size_t i = 0; i < primesBoolArray.size(); ++i)
        if (primesBoolArray[i])
            sum += i;

    return sum;
}

int main()
{
    std::cout << sumOfPrimesUpto(2000000) << "\n";
}
