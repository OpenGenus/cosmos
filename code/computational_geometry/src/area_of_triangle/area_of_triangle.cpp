#include <iostream>
typedef std::pair<double, double> point;

double calcArea(point a, point b, point c)
{
    return abs( (a.first - b.first) * (c.second - b.second) - (a.second - b.second) *
                (c.first - b.first) ) / 2;
}

int main ()
{
    point a, b, c;
    std::cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
    std::cout << calcArea(a, b, c);
}
