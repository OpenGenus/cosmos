#pragma once

#include <iostream>
#include <functional>

#include "solving_methods.hpp"

class Equation
{
  public:
    Equation(std::function<double(double)> f) : func_{f} {}

    void setMethod(SolvingMethod *m) { mthd_ = m; }

    void setFunction(std::function<double(double)> f) { func_ = f; }

    double solve() { return mthd_->solve(func_); }

  private:
    std::function<double(double)> func_;
    // This pointer to the abstract class SolvingMethod holds the algorithm
    // to be used for solving the equation.
    SolvingMethod *mthd_;
};
