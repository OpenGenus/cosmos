//  computational geometry | 2D line intersecton | C++
//  main.cpp
//  forfun
//
//  Created by Ivan Reinaldo Liyanto on 10/5/17.
//  Copyright © 2017 Ivan Reinaldo Liyanto. All rights reserved.
//  Path of Cosmos by OpenGenus Foundation

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct vec2
{
    double x;
    double y;
    vec2(double x, double y) : x(x), y(y)
    {
    }
};

/* return point of intersection, in parent's coordinate space of its parameters */
vec2 intersection(double x1, double y1, double x2, double y2, double x3, double y3, double x4,
                  double y4)
{
    double x12 = x1 - x2;
    double x34 = x3 - x4;
    double y12 = y1 - y2;
    double y34 = y3 - y4;

    double c = x12 * y34 - y12 * x34;

    double a = x1 * y2 - y1 * x2;
    double b = x3 * y4 - y3 * x4;

    double x = (a * x34 - b * x12) / c;
    double y = (a * y34 - b * y12) / c;
    return vec2(x, y);
}

/* line segments defined by 2 points a-b, and c-d */
vec2 intersection(vec2 a, vec2 b, vec2 c, vec2 d)
{
    return intersection(a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y);
}

int main()
{
    //example set 1
    vec2 a(10, 3);
    vec2 b(20, 10);
    vec2 c(10, 10);
    vec2 d(20, 3);

    //example set 2
//    vec2 a(10, 3);
//    vec2 b(20, 3);
//    vec2 c(10, 5);
//    vec2 d(20, 5);

    vec2 intersectionpoint = intersection(a, b, c, d);
    if (intersectionpoint.x >= min(a.x, b.x) && intersectionpoint.x <= max(a.x, b.x) &&
        intersectionpoint.y >= min(a.y, b.y) && intersectionpoint.y <= max(a.y, b.y))
        cout << "intersection: " << intersectionpoint.x << " " << intersectionpoint.y;
    else
        cout << "no intersection";

    return 0;
}
