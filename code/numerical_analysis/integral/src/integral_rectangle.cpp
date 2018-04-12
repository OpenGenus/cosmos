#include <iostream>
#include <functional>

//Part of Cosmos by OpenGenus Foundation
double integralRectangle(double a, double b, double step, std::function<double(double)> f)
{
    double fragment, res;
    fragment = (b - a) / step;
    res = step * (f(a) + f(b)) / 6.0;
    for (int i = 1; i <= fragment; ++i)
        res = res + 4.0 / 6.0 * step * f(a + step * (i - 0.5));

    for (int i = 1; i <= fragment - 1; ++i)
        res = res + 2.0 / 6.0 * step * f(a + step * i);
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
    res = integralRectangle(a, b, step, [](double x) -> double
    {
        return x;
    });
    std::cout << "Result: " << res << std::endl;
    return 0;
}
