/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point
{
    double x, y;
    point(double x, double y) : x(x), y(y)
    {
    }
    point()
    {
    }
};

// custom compare for sorting points
bool cmp(point a, point b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

// check clockwise orientation of points
bool cw(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

// check counter-clockwise orientation of points
bool ccw(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

// graham scan with Andrew improvements
void convex_hull(vector<point> &points)
{
    if (points.size() == 1)
        return;
    sort(points.begin(), points.end(), &cmp);
    point p1 = points[0], p2 = points.back();
    vector<point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (size_t i = 1; i < points.size(); ++i)
    {
        if (i == points.size() - 1 || cw(p1, points[i], p2))
        {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], points[i]))
                up.pop_back();
            up.push_back(points[i]);
        }
        if (i == points.size() - 1 || ccw(p1, points[i], p2))
        {
            while (down.size() >= 2 &&
                   !ccw(down[down.size() - 2], down[down.size() - 1], points[i]))
                down.pop_back();
            down.push_back(points[i]);
        }
    }
    cout << "Convex hull is:" << endl;
    for (size_t i = 0; i < up.size(); ++i)
        cout << "x: " << up[i].x << " y: " << up[i].y << endl;
    for (int i = down.size() - 2; i > 0; --i)
        cout << "x: " << down[i].x << " y: " << down[i].y << endl;
}

int main()
{
    int n;
    cout << "Enter number of points followed by points" << endl;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    convex_hull(points);
    return 0;
}
