/*
 * strategy.cpp
 *
 * Created : 5/31/2018 1:34:29 PM
 *  Author : n-is
 *   email : 073bex422.nischal@pcampus.edu.np
 */
#include <iostream>
#include <functional>
#include <math.h>

#include "equation.hpp"
#include "solving_methods.hpp"

int main()
{
    auto cubicFunc = [](double x) -> double {
        return x * x * x - 4 * x - 9;
    };

    auto sineFunc = [](double x) -> double {
        return x * sin(x) - cos(x);
    };

    Equation eqn(cubicFunc);
    SolvingMethod *method = new Bisection;

    // Here, we are choosing the solving algorithm for the equation at the
    // runtime.
    eqn.setMethod(method);

    std::cout << "Solving Cubic Function By " << method->name() << std::endl;
    std::cout << "The solution is : " << eqn.solve() << std::endl;
    std::cout << std::endl;

    method = new Secant;
    eqn.setFunction(sineFunc);

    // We are choosing new solving algorithm for the new equation at the
    // runtime here.
    eqn.setMethod(method);

    std::cout << "Solving Sine Function By " << method->name() << std::endl;
    std::cout << "The solution is : " << eqn.solve() << std::endl;

    return 0;
}
