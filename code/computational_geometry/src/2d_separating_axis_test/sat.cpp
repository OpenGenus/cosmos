// computational geometry | Two convex polygon intersection 2d seperating axis test | C++
//Ivan Reinaldo Liyanto
// open genus - cosmos
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
struct vec2
{
    double x, y;
    vec2(double x, double y) : x(x), y(y)
    {
    }
    friend vec2 operator+(vec2 lhs, const vec2& vec)
    {
        return vec2(lhs.x + vec.x, lhs.y + vec.y);
    }
    friend vec2 operator-(vec2 lhs, const vec2& vec)
    {
        return vec2(lhs.x - vec.x, lhs.y - vec.y);
    }

};

double dot(vec2 a, vec2 b)
{
    return a.x * b.x + a.y * b.y;
}

vector<vec2> inputPolygon1;
vector<vec2> inputPolygon2;

bool sat()
{
    //project every points onto every axis
    for (size_t i = 1; i < inputPolygon1.size(); i++)
    {
        vec2 axis = inputPolygon1[i] - inputPolygon1[i - 1];

        double leftMostPolygonA = __FLT_MAX__;
        double rightMostPolygonA = __FLT_MIN__;
        for (size_t j = 0; j < inputPolygon1.size(); j++)
        {
            double d = dot(inputPolygon1[j], axis);
            if (d > rightMostPolygonA)
                rightMostPolygonA = d;
            if (d < leftMostPolygonA)
                leftMostPolygonA = d;
        }

        double leftMostPolygonB = __FLT_MAX__;
        double rightMostPolygonB = __FLT_MIN__;
        for (size_t j = 0; j < inputPolygon2.size(); j++)
        {
            double d = dot(inputPolygon2[j], axis);
            if (d > rightMostPolygonB)
                rightMostPolygonB = d;
            if (d < leftMostPolygonB)
                leftMostPolygonB = d;
        }

        if ((leftMostPolygonB < rightMostPolygonA && rightMostPolygonB > rightMostPolygonA) ||
            (leftMostPolygonA < rightMostPolygonB && rightMostPolygonA > rightMostPolygonB) )
            return true;
    }

    //false = no intersection
    return false;
}

int main()
{
    //given 2 convex polygons defined by set of points, determine if the two polygon intersects using Separating Axis Test
    //example set 1
    inputPolygon1.push_back(vec2(5, 5));
    inputPolygon1.push_back(vec2(7, 10));
    inputPolygon1.push_back(vec2(15, 10));
    inputPolygon1.push_back(vec2(4, 4));

    inputPolygon2.push_back(vec2(6, 6));
    inputPolygon2.push_back(vec2(0, 0));
    inputPolygon2.push_back(vec2(7, 0));

    cout << "The two polygons " << (sat() ? "" : "do not ") << "intersect\n";

    return 0;
}
