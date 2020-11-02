#include <algorithm>
#include <iostream>
#include <vector>

int sumProperDivisors(int n)
{
    int sum = 0;
    for (int i = 1; i*i <= n; ++i)
        if (n % i == 0) {
            sum += i;
            if(n / i != i)
                sum += n / i;
        }
    return sum - n;
}

void findAbundantNumbers(int limit, std::vector<int> &numbers)
{
    for (int i = 1; i <= limit; ++i)
        if (sumProperDivisors(i) > i)
            numbers.push_back(i);
}

bool isSumOfAbundantNumbers(int n, const std::vector<int> &numbers)
{
    for (int i = 0; i < numbers.size() && numbers[i] < n; ++i)
        if (std::binary_search(numbers.begin(), numbers.end(), n - numbers[i]))
            return true;
    return false;
}

int main()
{
    int sum = 0, max = 28123;
    std::vector<int> numbers;
    findAbundantNumbers(max, numbers);
    for (int i = 1; i <= max; ++i)
        if (!isSumOfAbundantNumbers(i, numbers))
            sum += i;

    std::cout << sum << std::endl;
    return 0;
}
