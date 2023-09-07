#pragma once

#include <iostream>
#include <functional>

/* This file contains algorithms to solve any single vavriable equation. We can
 * add more algorithms by simply creating a new class and implementing
 * SolvingMethod interface in it.
 */

class SolvingMethod
{
  public:
    virtual double solve(std::function<double(double)> func) const = 0;
    virtual const char *name() const = 0;

    virtual ~SolvingMethod() {}

  protected:
    // This constant determines the correctness of the solution. Smaller value
    // means better solution.
    const double AllowedError_ = 0.001;
    // This constant determines the threshold for zero. Any value whose absolute
    // value is less than this number will be considered as zero.
    const double NearlyZero_ = 0.00001;

    // This function simply finds the range in which the solution exists.
    static double guess(std::function<double(double)> func, double resolution);
};

/* Bisection Method solves a single variable equation by repeatedly bisecting
 * an interval and then selecting a subinterval in which a root must lie for
 * further processing.
 * For more info : https://en.wikipedia.org/wiki/Bisection_method
 */
class Bisection : public SolvingMethod
{
  public:
    const char *name() const { return "Bisection Method"; }

    double solve(std::function<double(double)> func) const;
};

/* Secant Method uses a succession of roots of secant lines to better
 * approximate a root of a function.
 * For more info : https://en.wikipedia.org/wiki/Secant_method
 */
class Secant : public SolvingMethod
{
  public:
    const char *name() const { return "Secant Method"; }

    double solve(std::function<double(double)> func) const;
};
