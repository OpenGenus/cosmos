#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

using xy = std::pair<double, double>;

std::vector<xy> rungeKutt(xy startConditions,
                          double startInterval,
                          double finishInterval,
                          double step,
                          std::function<double(double, double)> f)
{
    std::vector<xy> res;
    unsigned int numberSteps = std::ceil((finishInterval - startInterval) / step);
    double k1, k2, k3, k4;
    res.reserve(numberSteps + 1);
    res.push_back(startConditions);
    for (unsigned int i = 0; i < numberSteps; ++i)
    {
        k1 = step * f(startConditions.first, startConditions.second);
        k2 = step * f(startConditions.first + step / 2.0, startConditions.second + k1 / 2.0);
        k3 = step * f(startConditions.first + step / 2.0, startConditions.second + k2 / 2.0);
        k4 = step * f(startConditions.first + step, startConditions.second + k3 );
        startConditions.second += (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
        startConditions.first += step;
        res.push_back(startConditions);
    }
    return res;
}

int main()
{
    xy startConditions;
    double startInterval, finishInterval, step;
    std::vector<xy> res;
    std::cout << "Enter start condition:" << "\n";
    std::cout << "X = " << std::endl;
    std::cin >> startConditions.first;
    std::cout << "Y = " << std::endl;
    std::cin >> startConditions.second;
    std::cout << "Enter interval:" << "\n";
    std::cout << "Start = " << std::endl;
    std::cin >> startInterval;
    std::cout << "Finish = " << std::endl;
    std::cin >> finishInterval;
    std::cout << "Enter step: " << std::endl;
    std::cin >> step;
    auto func = [](double x, double y) -> double
                {
                    return std::pow(x, 2) * (3 * y + std::exp(std::pow(x, 3)));
                };
    res = rungeKutt(startConditions, startInterval, finishInterval, step, func);

    for (auto it = res.begin(); it != res.end(); ++it)
        std::cout << "X = " << it->first << "   Y = " << it->second << std::endl;
    return 0;
}
