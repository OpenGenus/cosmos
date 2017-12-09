#include <iostream>
#include <random>

//Part of Cosmos by OpenGenus Foundation
double piMonteCarlo(double pointCount)
{
    double circlePoints = 0;
    double pi, x, y;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis;
    for (int i = 0; i < pointCount; ++i)
    {
        x = dis(gen);
        y = dis(gen);
        if (x * x + y * y < 1)
            circlePoints++;
    }
    pi = (circlePoints / pointCount) * 4;
    return pi;
}

int main()
{
    double pointCount, pi;
    std::cout << "Enter point count: " << std::endl;
    std::cin >> pointCount;
    pi = piMonteCarlo(pointCount);
    std::cout << "Pi = " << pi << std::endl;
    return 0;
}
