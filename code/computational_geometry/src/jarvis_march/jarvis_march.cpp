#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point
{
    int x;
    int y;
    int pos;
    Point(int x, int y, int p)
    {
        this->x = x;
        this->y = y;
        this->pos = p;
    }
};

int orientation(Point p, Point q, Point r)
{
    int cross = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (cross == 0)
        return 0;
    return (cross > 0) ? 1 : -1;
}

vector<Point> getConvexHull(vector<Point> points)
{
    if (points.size() < 3)
        return points;

    int left = 0;
    for (size_t i = 1; i < points.size(); i++)
        if (points[i].x < points[left].x)
            left = i;

    // Starting from left move counter-clockwise
    vector<Point> hull;
    int tail = left, middle;
    do {
        middle = (tail + 1) % points.size();
        for (size_t i = 0; i < points.size(); i++)
            if (orientation(points[tail], points[i], points[middle]) == -1)
                middle = i;

        hull.push_back(points[middle]);
        tail = middle;
    } while (tail != left);

    return hull;
}

double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main()
{
    int N;
    cin >> N;
    vector<Point> points;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back(Point(x, y, i + 1));
    }

    vector<Point> result = getConvexHull(points);
    result.push_back(result[0]);
    double ans = 0;
    for (size_t i = 1; i < result.size(); i++)
        ans += dist(result[i], result[i - 1]);

    cout << ans << '\n';
    cout << "Points lying on hull\n";
    for (size_t i = 0; i < result.size(); i++)
        cout << result[i].pos << ' ';
}
