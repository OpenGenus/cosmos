#include <iostream>
using namespace std;

//change this differential equation
double dydx(double x, double y)
{
    return x + y;
}

void eulerApproximation(double x_min, double y_min, double x_max, double dx)
{
    /*
     * x_min : minimum x value, initial point x for approximation
     * y_min : minimum y value, initial point y for approximation
     * x_max : maximum x value, end point x for approximation
     * dx : small change in x(delta x)
     */

    double dy, y = y_min;
    for (double i = x_min; i <= x_max; i += dx)
    {
        dy = dydx(i, y);
        cout << "x: " << i << "\t\t";
        cout << "y: " << y << "\t\t";
        cout << "slope: " << dy;
        cout << endl;
        y += dx * dy;
    }
}

int main()
{
    double x_min = 0, y_min = 1, x_max = 5, dx = 0.1;
    eulerApproximation(x_min, y_min, x_max, dx);
    return 0;
}
