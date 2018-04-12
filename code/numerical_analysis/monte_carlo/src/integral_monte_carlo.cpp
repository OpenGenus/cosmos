#include <iostream>
#include <functional>
#include <random>

//Part of Cosmos by OpenGenus Foundation
double integralMonteCarlo(double a, double b, double pointCount, std::function<double(double)> f)
{
    double res, randX, randY;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis;
    for (int i = 0; i < pointCount; ++i)
    {
        randX = ((b - a) * dis(gen)) + a;
        randY += f(randX);
    }
    res = (b - a) * (randY / pointCount);
    return res;
}

int main()
{
    double a, b, pointCount, res;
    std::cout << "Enter interval: " << std::endl;
    std::cout << "a: " << std::endl;
    std::cin >> a;
    std::cout << "b: " << std::endl;
    std::cin >> b;
    std::cout << "Enter point count: " << std::endl;
    std::cin >> pointCount;
    res = integralMonteCarlo(a, b, pointCount, [](double x) -> double
    {
        return x * x + x;
    });
    std::cout << "Result: " << res << std::endl;
    return 0;
}
