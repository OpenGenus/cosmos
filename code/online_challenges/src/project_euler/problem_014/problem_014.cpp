#include <iostream>

long long int collatzSequenceSize(long long int n)
{
    long long int result = 0;
    while (n != 1)
    {
        n = (n % 2 == 0) ? n / 2 : n * 3 + 1;
        ++result;
    }
    return result;
}

int main()
{
    long long int l = 0;
    long long int lSize = 0;
    for (long long int i = 1; i < 1000000; ++i)
    {
        long long int currentSize = collatzSequenceSize(i);
        if (currentSize > lSize)
        {
            l = i;
            lSize = currentSize;
        }
    }

    std::cout << l << "\n";
}
