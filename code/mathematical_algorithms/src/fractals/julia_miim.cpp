// This is a simple code to generate Julia sets of quadratic functions
// of the form f(z) = z^2 + c.
//
// The algorithm used is the Modified Inverse Iteration Method described in
//
//   Heinz-Otto Peitgen, Dietmar Saupe, eds., The Science of Fractal Images
//   Springer-Verlag, New York, 1988. pp. 178
//   ISBN 0-387-96608-0
//

#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

double randUnit()
{
    return ((double)rand()) / RAND_MAX;
}

double randInterval(double a, double b)
{
    return a + (b - a) * randUnit();
}

void inverseStep(double wx,
                 double wy,
                 vector< vector<int>>& grid,
                 const double cx,
                 const double cy,
                 const int Nmax,
                 const int res,
                 const int depth,
                 const int maxdepth)
{

    // Check for end of recursion
    if (depth >= maxdepth)
        return;

    // This point is good, so write it out
    cout << wx << ' ' << wy << endl;

    double r, theta;
    int xneg, yneg, xpos, ypos; // grid coordinates

    // convert to polar coordinates
    r = sqrt((wx - cx) * (wx - cx) + (wy - cy) * (wy - cy));
    theta = atan2(wy - cy, wx - cx);

    // find inverse using f^(-1)(w) = +/-sqrt(w - c)
    wx = sqrt(r) * cos(theta / 2.0);
    wy = sqrt(r) * sin(theta / 2.0);

    // translate complex plane coordinates to grid coordinates
    xpos = static_cast<int>(floor( (res * (wx + 2.0)) / 4.0) );
    ypos = static_cast<int>(floor( (res * (wy + 2.0)) / 4.0) );
    xneg = static_cast<int>(floor( (res * (-wx + 2.0)) / 4.0) );
    yneg = static_cast<int>(floor( (res * (-wy + 2.0)) / 4.0) );

    if (grid[xpos][ypos] < Nmax)
    {
        grid[xpos][ypos]++;
        inverseStep(wx, wy, grid, cx, cy, Nmax, res, depth + 1, maxdepth);
    }
    if (grid[xneg][yneg] < Nmax)
    {
        grid[xneg][yneg]++;
        inverseStep(-wx, -wy, grid, cx, cy, Nmax, res, depth + 1, maxdepth);
    }
}


int main()
{
    double cx, cy; // real and imaginary parts of c parameter
    double wx, wy; // real and imaginary parts of iterated value
    int Nmax;    // max number of points per grid box
    int res;     // resolution of the grid
    int maxdepth; // maximum depth of tree search

    srand(time(NULL)); // seed the random number generator with the system clock

    cin >> cx >> cy >> Nmax >> res >> maxdepth;

    assert(Nmax > 0);
    assert(res >= 10);
    assert((res % 2) == 0);
    assert(maxdepth > 0);

    // The grid ranges from -2...+2 in both the x and y directions
    vector< vector<int>> grid;
    vector<int> empty_row(res, 0);
    for (int i = 0; i < res; ++i)
        grid.push_back(empty_row);

    // Randomly pick a point somewhat near the origin with which
    // to start iterating.
    wx = randInterval(-1.0, 1.0);
    wy = randInterval(-1.0, 1.0);

    double r, theta;
    double sign;
    int xneg, yneg, xpos, ypos; // grid coordinates

    // Quickly do some iterations randomly picking one of the roots so
    // that we get close to J_c before selectively picking roots.
    int i = 0;
    while (i < 50)
    {
        // original function  f(z) = z^2 + c
        // inverse function   f^(-1)(w) = +/-sqrt(w - c)
        r = sqrt((wx - cx) * (wx - cx) + (wy - cy) * (wy - cy));
        theta = atan2(wy - cy, wx - cx);

        sign = (randUnit() < 0.5) ? -1.0 : 1.0;
        wx = sign * sqrt(r) * cos(theta / 2.0);
        wy = sign * sqrt(r) * sin(theta / 2.0);

        ++i;
    }

    xpos = static_cast<int>(floor( (res * (wx + 2.0)) / 4.0) );
    ypos = static_cast<int>(floor( (res * (wy + 2.0)) / 4.0) );
    xneg = static_cast<int>(floor( (res * (-wx + 2.0)) / 4.0) );
    yneg = static_cast<int>(floor( (res * (-wy + 2.0)) / 4.0) );

    grid[xpos][ypos]++;
    inverseStep(wx, wy, grid, cx, cy, Nmax, res, 0, maxdepth);

    grid[xneg][yneg]++;
    inverseStep(-wx, -wy, grid, cx, cy, Nmax, res, 0, maxdepth);

    return 0;
}
