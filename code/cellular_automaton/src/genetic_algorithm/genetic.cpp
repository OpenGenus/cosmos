/**
 * Root finding using genetic algorithm (Uses C++11).
 * Reference: https://arxiv.org/abs/1703.03864
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

struct StopCondition
{
    StopCondition(double tol, long iter)
        : tolerance(tol)
        , iterations(iter)
    {
    }
    double tolerance;
    long iterations;
};

struct GAConfig
{
    GAConfig(double learning_rate, double variance, long generation_size)
        : lr(learning_rate)
        , var(variance)
        , size(generation_size)
    {
        factor = lr / (var * size);
    }
    double lr;
    double var;
    long size;
    double factor;
};

template <typename UnaryFunc>
double solve(UnaryFunc f, double initial, GAConfig conf, StopCondition cond)
{
    std::default_random_engine gen;
    std::normal_distribution<double> normal(0, 1);

    std::vector<double> noise(conf.size);
    std::vector<double> generation(conf.size);
    std::vector<double> fitness(conf.size);

    double x = initial, error = 0;
    long iter = 0;

    do {
        double delta = 0;
        for (int i = 0; i < conf.size; ++i)
        {
            noise[i] = normal(gen);
            generation[i] = x + conf.var * noise[i];
            fitness[i] = exp(-abs(f(generation[i])));
            delta += fitness[i] * noise[i];
        }
        x = x + conf.factor * delta;
        error = std::abs(f(x));
        std::cout << iter + 1 << "\tx = " << x << "\t error = " << error
                  << std::endl;
    } while ((error > cond.tolerance) && (++iter < cond.iterations));

    return x;
}

int main()
{
    auto f = [](double x)
             {
                 return (x - 1.0) * (x - 2.0);
             };

    auto config = GAConfig{ 0.2, 0.1, 10 };
    auto stop_condition = StopCondition{ 1e-3, 10000 };
    double solution = solve(f, 0.0, config, stop_condition);

    std::cout << solution << std::endl;
}
