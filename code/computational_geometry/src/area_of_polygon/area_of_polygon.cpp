#include <iostream>
typedef std::pair<double, double> point;

const int size = 100000;

point points[size];

#define x first
#define y second

double calcArea(point a, point b, point c)
{
    return abs( (a.first - b.first) * (c.second - b.second) - (a.second - b.second) *
                (c.first - b.first) ) / 2;
}

int main ()
{
    double answer = 0;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
        std::cin >> points[i].x >> points[i].y;

    for (int i = 2; i < n; i++)
        answer += calcArea(points[0], points[i - 1], points[i]);

    std::cout << answer;
}
