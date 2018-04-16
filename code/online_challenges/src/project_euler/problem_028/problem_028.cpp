#include <iostream>
#include <cmath>

bool isPerfectSquare(int num)
{
    int sqrtNum = static_cast<int>(std::sqrt(num));
    return sqrtNum * sqrtNum == num;
}

int main()
{
    int limit = 1001 * 1001;
    int incrementRate = 0;
    int diagonalNumberSum = 0;
    for (int i = 1; i <= limit; i += incrementRate) // Iterate over every diagonal number
    {
        diagonalNumberSum += i; // Add the current diagonal number
        if ((i % 2 == 1)         // If the current number is odd
            && isPerfectSquare(i)) // and it is a perfect square
                                   // then we have reached the next spiral
            incrementRate += 2;
    }

    std::cout << diagonalNumberSum << "\n";
}
