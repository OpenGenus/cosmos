#include <array>
#include <cmath>
#include <iostream>

template<std::size_t N>
std::array<bool, N> primesUpto() // Function that implements the Sieve of Eratosthenes
{
    std::array<bool, N> primesList;

    std::fill(primesList.begin(), primesList.end(), true);

    primesList[0] = primesList[1] = false;

    std::size_t sqrtLimit = std::sqrt(N) + 1;

    for (std::size_t i = 0; i < sqrtLimit; ++i)
        if (primesList[i])
            for (std::size_t j = i + i; j < N; j += i)
                primesList[j] = false;

    return primesList;
}

template<std::size_t N>
bool isTruncPrime(std::size_t number, const std::array<bool, N>& primesList)
{
    for (std::size_t i = 10; i < number; i *= 10)
        if (!primesList[number % i]) // If the right truncated part is not prime
            return false;
    for (; number >= 1; number /= 10)
        if (!primesList[number]) // If the left truncated part is not prime
            return false;

    return true; // All truncated parts are prime, so the number is a truncatable prime
}

int main()
{
    const auto primesUptoMillion = primesUpto<1000000ULL>(); // Represents all the primes up to 1 million

    std::size_t numberTruncatablePrimes = 0;
    std::size_t currentNumber = 11; // 2, 3, 5, and 7 are not included in the search for truncatable primes
    std::size_t truncatablePrimeSum = 0;

    while (numberTruncatablePrimes != 11)
    {
        if (primesUptoMillion[currentNumber] && // If the number itself is prime
            isTruncPrime(currentNumber, primesUptoMillion)) // If the number is also a truncatable prime
        {
            ++numberTruncatablePrimes; // Increase amount of truncatable primes
            truncatablePrimeSum += currentNumber; // Add the number's sum
        }
        currentNumber += 2; // Only odd numbers can be prime other than 2, so no need to look at every number
    }
    std::cout << truncatablePrimeSum << "\n";
}
