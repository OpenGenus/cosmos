#include <iostream>
#include <vector>

int factorial (std::size_t n)
{
    int fact = 1;
    for (std::size_t i = 1; i <= n; ++i)
        fact *= i;
    return fact;
}

int main()
{
    std::vector<int> factorials(10);
    constexpr std::size_t maxDigitFactorial = 2540162;
    for (int i = 0; i < 10; ++i)
        factorials[i] = factorial(i);
    std::size_t num = 3, sum = 0;
    while (num < maxDigitFactorial)
    {
        std::size_t temp = 0;
        for (std::size_t i = num; i > 0; i /= 10)
            temp += factorials[i % 10];
        if (temp == num)
            sum += num;
        ++num;
    }
    std::cout << sum << "\n";
}
