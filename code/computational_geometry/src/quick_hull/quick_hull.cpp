#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

struct vec2
{
    float x, y;
    vec2(float x, float y) : x(x), y(y)
    {
    }
    vec2()
    {
    }
};

vector<vec2> input;
vector<vec2> output;


float lineToPointSupport(vec2 l1, vec2 l2, vec2 p)
{
    return abs ((p.y - l1.y) * (l2.x - l1.x) -
                (l2.y - l2.y) * (p.x - l1.x));
}

float dot(vec2 A, vec2 B)
{
    return A.x * B.x + A.y * B.y;
}


void findHull(int a, int b)
{
    float dy = input[b].y - input[a].y;
    float dx = input[b].x - input[a].x;
    vec2 normal(-dy, dx);
    float biggestLinePointDistance = -1;
    int c = 0;

    for (size_t i = 0; i < input.size(); i++)
    {
        vec2 aToPoint(input[i].x - input[a].x, input[i].y - input[a].y);
        if (dot(aToPoint, normal) < 0 || static_cast<int>(i) == a || static_cast<int>(i) == b)
            continue;
        float lineToPoint = lineToPointSupport(input[a], input[b], input[i]);
        if (lineToPoint > biggestLinePointDistance)
        {
            c = i;
            biggestLinePointDistance = lineToPoint;
        }
    }

    if (biggestLinePointDistance == -1)
        return;
    output.push_back(input[c]);
    findHull(a, c);
    findHull(c, b);
}


void quickhull()
{
    if (input.size() < 3)
        return;

    float mini = 0;
    float maxi = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i].x < input[mini].x)
            mini = i;
        if (input[i].x > input[maxi].x)
            maxi = i;
    }
    output.push_back(input[mini]);
    output.push_back(input[maxi]);
    findHull(mini, maxi);
    findHull(maxi, mini);
}

int main()
{

    //example set 1
    input.push_back(vec2(5, 10));
    input.push_back(vec2(10, 10));
    input.push_back(vec2(7, 15));
    input.push_back(vec2(7, 13));

    //example set 2
//    input.push_back(vec2(0, 15));
//    input.push_back(vec2(10, 15));
//    input.push_back(vec2(10, 20));
//    input.push_back(vec2(0, 20));
//    input.push_back(vec2(5, 17));
    quickhull();
    for (size_t i = 0; i < output.size(); i++)
        cout << "x: " << output[i].x << "y: " << output[i].y << endl;
    return 0;
}
