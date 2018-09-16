#include <iostream>
#include <cmath>

int main()
{
    int divisorCount = 0;
    int triangleNumberIndex = 0;
    int triangleNumber = 0;

    while (divisorCount < 500)
    {
        divisorCount = 0;
        ++triangleNumberIndex;
        triangleNumber += triangleNumberIndex;
        for (int i = 1; i < std::sqrt(triangleNumber) + 1; ++i)
            if (triangleNumber % i == 0)
                divisorCount += (i * i == triangleNumber) ? 1 : 2;
    }

    std::cout << triangleNumber << "\n";
    return 0;
}
