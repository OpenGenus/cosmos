/*
 * The method of steepest descent
 * -------------------
 * An algorithm for finding the nearest local minimum of a function.
 * It solves an equation in quadratic form: Ax = b where x is the values we seek.
 * A is a matrix of size NxN, and b is a vector of N values.
 *
 * Time complexity
 * ---------------
 * O(e^-2), where e is an error we can accept (indicates how far we are from solution).
 *
 * Space complexity
 * ----------------
 * O(2*N), where N is a size of matrix
 */

#include <iostream>
#include <array>
#include <cmath>

/*
 * Evalutates euclidean norm
 */
template <long unsigned int S>
double norm(const std::array<double, S> &x, const std::array<double, S> &y)
{
    double result = 0;
    for (unsigned int i = 0; i < S; ++i)
        result += (x[i] - y[i]) * (x[i] - y[i]);
    return std::move(sqrt(result));
}

/*
 * Adds up two matrix
 */
template <long unsigned int S>
std::array<double, S> operator+(const std::array<double, S> &x, const std::array<double, S> &y)
{
    std::array<double, S> result;

    for (unsigned int i = 0; i < S; ++i)
        result[i] = x[i] + y[i];
    return std::move(result);
}

/*
 * Subtrack two matrix
 */
template <long unsigned int S>
std::array<double, S> operator-(const std::array<double, S> &x, const std::array<double, S> &y)
{
    std::array<double, S> result;

    for (unsigned int i = 0; i < S; ++i)
        result[i] = x[i] - y[i];
    return std::move(result);
}

/*
 * Multiplication of matrix and constant value
 */
template <long unsigned int S>
std::array<double, S> operator*(const double x, const std::array<double, S> &y)
{
    std::array<double, S> result;

    for (unsigned int i = 0; i < S; ++i)
        result[i] = x * y[i];
    return std::move(result);
}

/*
 * Multiplication of NxN and Nx1 matrix
 */
template <long unsigned int S>
std::array<double, S> operator*(const std::array<std::array<double, S>, S> &A,
                                const std::array<double, S> &b)
{
    std::array<double, S> result = {0.0};

    for (unsigned int i = 0; i < S; ++i)
        for (unsigned int j = 0; j < S; ++j)
            result[i] += A[i][j] * b[j];

    return result;
}

/*
 * Method of Steepest Descent
 */
template <long unsigned int S>
std::array<double, S> steepestdescent(const std::array<std::array<double, S>, S> &A,
                                      const std::array<double, S> &b,
                                      const double e = 0.0001, const double step = 0.1,
                                      const unsigned int IterMax = 10000)
{
    std::array<double, S> x = {0.0};
    unsigned int k = 0;

    do
    {
        std::array<double, S> xp = x;
        std::array<double, S> residual = b - A * xp;
        x = x + step * residual;
        if (norm(x, xp) < e)
            break;
        k += 1;
    }
    while (k < IterMax);

    return std::move(x);
}

/*
 * Overloads operator << to display NxN size array
 */
template <long unsigned int S>
std::ostream &operator<<(std::ostream &stream, const std::array<std::array<double, S>, S> &A)
{
    for (std::array<double, S> tmp : A)
    {
        for (double i : tmp)
            stream << i << '\t';
        stream << '\n';
    }
    return stream;
}

/*
 * Overloads operator << to display Nx1 size array
 */
template <long unsigned int S>
std::ostream &operator<<(std::ostream &stream, const std::array<double, S> &x)
{
    for (double i : x)
        stream << i << '\n';
    return stream;
}

int main()
{
    const long unsigned int S = 3;
    const std::array<std::array<double, S>, S> A = {1, -1, 1, 1, 1, 0, 1, 2, 0};
    const std::array<double, S> b = {9, 1, -2};
    std::array<double, S> x;
    std::array<double, S> tmp;


    // std::cout << "Maxtrix A:\n"<< A << '\n';
    std::cout << "Vector b:\n" << b << '\n';
    x = steepestdescent(A, b, 0.0000001);
    std::cout << "Result:\n" << x << '\n';
    tmp = A * x;
    std::cout << "Ax = :\n" << tmp << '\n';

    return 0;
}
