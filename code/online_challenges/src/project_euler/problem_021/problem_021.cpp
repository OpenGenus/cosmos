#include <iostream>

int sumProperDivisors(int n)
{
    int sum = 0;
    for (int i = 1; i * i <= n; ++i)
        if (n % i == 0)
        {
            sum += i;
            if (n / i != i)
                sum += n / i;
        }
    return sum - n;
}

bool isAmicableNumber(int n)
{
    int m = sumProperDivisors(n);
    return m != n && sumProperDivisors(m) == n;
}

int main()
{
    int result = 0;
    for (int i = 1; i < 10000; ++i)
        if (isAmicableNumber(i))
            result += i;

    std::cout << result << std::endl;
    return 0;
}
