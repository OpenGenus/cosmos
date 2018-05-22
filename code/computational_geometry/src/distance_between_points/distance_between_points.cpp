#include <iostream>
#include <cmath>

typedef std::pair<double, double> point;

#define x first
#define y second

double calcDistance (point a, point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main ()
{
    point a, b, c;
    std::cin >> a.x >> a.y >> b.x >> b.y;
    std::cout << calcDistance(a, b);
}
