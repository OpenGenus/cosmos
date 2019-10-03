/* Part of Cosmos by OpenGenus Foundation */
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>

// This code requires you to enable the C++11 standard when compiling

void helpAndExit()
{
    std::cout << "Newton-Raphson iteration for the function x*log10(x)-1.2\n"
              << "\nUsage: newton-raphson INITIAL_GUESS ERROR_LIMIT MAX_ITERATIONS\n"
              << "\tINITIAL_GUESS - The initial guess (x0). A number.\n"
              << "\tERROR_LIMIT - The stopping condition. A positive number.\n"
              << "\tMAX_ITERATIONS - The maximum number of allowed iterations. A positive number.\n"
              << "\n\tExample: newton_raphson 1 0.001 1000" << std::endl;
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc != 4)
        helpAndExit();

    float x0, allowedError;
    int maxIterations;

    try {
        x0 = std::stof(std::string(argv[1]));
        allowedError = std::stof(std::string(argv[2]));
        maxIterations = std::stoi(std::string(argv[3]));

        if (allowedError < 0.0f || maxIterations < 0)
            throw std::domain_error("Error limit and number of iterations must be positive numbers!");

    } catch (std::exception& e)
    {
        std::cout << e.what() << "\n" << std::endl;
        helpAndExit();
    }

    auto f = [](const float x)
             {
                 return x * std::log10(x) - 1.2;
             };
    auto df = [](const float x)
              {
                  return std::log10(x) + 0.43429;
              };

    for (auto i = 1; i < maxIterations; i++)
    {
        const auto error = f(x0) / df(x0);

        if (std::fabs(error) < allowedError)
        {
            std::cout << "Conversion reached after: " << i << " iterations. Solution: " << x0 <<
                std::endl;
            return 0;
        }

        x0 = x0 - error;
    }

    std::cout << "Convergence not reached after " << maxIterations << " iterations" << std::endl;

    return 0;
}
