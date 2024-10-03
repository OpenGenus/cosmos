#include "solving_methods.hpp"
#include <math.h>

double SolvingMethod::guess(std::function<double(double)> func, double resolution)
{
    double ig(0), fg(resolution);
    double lastOddIg(ig), lastOddFg(fg);
    double lastEvenIg(ig), lastEvenFg(fg);
    long long n = 1;

    do
    {
        if (func(ig) * func(fg) <= 0)
            return ig;

        if (n++ % 2)
        {
            lastOddIg = ig;
            lastOddFg = fg;
            ig = lastEvenIg - resolution;
            fg = lastEvenFg - resolution;
        }
        else
        {
            lastEvenIg = ig;
            lastEvenFg = fg;
            ig = lastOddIg + resolution;
            fg = lastOddFg + resolution;
        }
    } while (n < 10000000);

    std::cout << "Guessing took too long.\n";
    exit(1);
}

double Bisection::solve(std::function<double(double)> func) const
{
    double a, b, c;
    int resolution = 2;

    // Guess the brackets of the given function
    a = guess(func, resolution);
    b = a + resolution;

    // Checking if any one of the brackets is the solution itself.
    if (fabs(func(a)) < AllowedError_)
        return a;

    else if (fabs(func(b)) < AllowedError_)
        return b;

    // Since we are certain that the solution lies within (a,b) at this
    // step, we simply calculate the value until we get satisfactory answer.
    do
    {
        c = (a + b) / 2;

        if (fabs(func(c)) < AllowedError_)
            return c;

        if (func(a) * func(c) < 0)
            b = c;
        else
            a = c;
    } while (1);
}

double Secant::solve(std::function<double(double)> func) const
{
    double a, b, c;
    int resolution = 2;

    /* Guess the brackets of the given function
     * For this method, finding bracket is not necessary, but with brackets,
     * we can be sure that the solution exists and the solution converges
     * faster with brackets.
     */
    a = guess(func, resolution);
    b = a + resolution;

    // Checking if any one of the brackets is the solution itself.
    if (fabs(func(a)) < AllowedError_)
        return a;

    else if (fabs(func(b)) < AllowedError_)
        return b;

    // Since we are certain that the solution lies within (a,b) at this
    // step, we simply calculate the value until we get satisfactory answer.
    do
    {
        double denom = func(b) - func(a);
        if (fabs(denom) < NearlyZero_)
        {
            std::cout << "Denominator Error!!\n";
            exit(1);
        }

        c = (a * func(b) - b * func(a)) / denom;

        if (fabs(func(c)) < AllowedError_)
            return c;

        a = b;
        b = c;
    } while (1);
}