#include <iostream>

int main()
{
    long long int sumOfSquares = 0LL;
    long int squareOfSum = 0LL;

    for (int n = 1; n <= 100; ++n)
    {
        sumOfSquares += (n * n);
        squareOfSum += n;
    }
    squareOfSum *= squareOfSum;

    std::cout << (squareOfSum - sumOfSquares) << "\n";
}
