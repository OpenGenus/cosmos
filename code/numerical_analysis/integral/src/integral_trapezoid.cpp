#include <iostream>
#include <functional>

//Part of Cosmos by OpenGenus Foundation
double integralTrapezoid(double a, double b, double step, std::function<double(double)> f)
{
    double fragment, res;
    fragment = (b - a) / step;
    res = step * (f(a) + f(b)) / 2.0;
    for (int i = 1; i <= fragment - 1; ++i)
        res = res + step * f(a + step * i);
    return res;
}

int main()
{
    double a, b, step, res;
    std::cout << "Enter interval: " << std::endl;
    std::cout << "a: " << std::endl;
    std::cin >> a;
    std::cout << "b: " << std::endl;
    std::cin >> b;
    std::cout << "Enter integration step: " << std::endl;
    std::cin >> step;
    res = integralTrapezoid(a, b, step, [](double x) -> double
    {
        return x;
    });
    std::cout << "Result: " << res << std::endl;
    return 0;
}
