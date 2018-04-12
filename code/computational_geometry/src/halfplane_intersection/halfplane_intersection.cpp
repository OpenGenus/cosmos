#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const double INF = 1e9;
const double EPS = 1e-8;

class Point {
public:
    double x, y;
    Point()
    {
    }
    Point(double x, double y) : x(x), y(y)
    {
    }
    bool operator==(const Point &other) const
    {
        return abs(x - other.x) < EPS && abs(y - other.y) < EPS;
    }
    Point operator-(const Point &a) const
    {
        return Point(x - a.x, y - a.y);
    }
    double operator^(const Point &a) const
    {
        return x * a.y - a.x * y;
    }
    void scan()
    {
        cin >> x >> y;
    }
    void print() const
    {
        cout << x << " " << y << "\n";
    }
};

class Line {
public:
    double a, b, c;
    Line()
    {
    }
    Line(double a, double b, double c) : a(a), b(b), c(c)
    {
    }
    Line(const Point &A, const Point &B) : a(A.y - B.y), b(B.x - A.x),
        c(A.x * (B.y - A.y) + A.y * (A.x - B.x))
    {
    }
    bool operator==(const Line &other) const
    {
        return a == other.a && b == other.b && c == other.c;
    }
    bool contains_point(const Point &A) const
    {
        return a * A.x + b * A.y + c == 0;
    }
    bool intersects(const Line &l) const
    {
        return !(a * l.b == b * l.a);
    }
    Point intersect(const Line &l) const
    {
        return Point(-(c * l.b - l.c * b) / (a * l.b - l.a * b),
                     -(a * l.c - l.a * c) / (a * l.b - l.a * b));
    }
};

class Segment {
private:
    Point A, B;
public:
    Segment()
    {
    }
    Segment(Point A, Point B) : A(A), B(B)
    {
    }
    bool intersects(const Line &l) const
    {
        return l.intersects(Line(A, B)) &&
               l.intersect(Line(A, B)).x <= max(A.x, B.x) + EPS &&
               l.intersect(Line(A, B)).x >= min(A.x, B.x) - EPS &&
               l.intersect(Line(A, B)).y <= max(A.y, B.y) + EPS &&
               l.intersect(Line(A, B)).y >= min(A.y, B.y) - EPS;
    }

    double length2() const
    {
        return (A - B).x * (A - B).x + (A - B).y * (A - B).y;
    }

    double length() const
    {
        return sqrt(length2());
    }
};

class HalfPlane {
private:
    double a, b, c;
public:
    HalfPlane()
    {
    }
    HalfPlane(Line l, Point A)
    {
        if (l.a * A.x + l.b * A.y + l.c < 0)
        {
            a = -l.a;
            b = -l.b;
            c = -l.c;
        }
        else
        {
            a = l.a;
            b = l.b;
            c = l.c;
        }
    }
    bool contains_point(const Point &p) const
    {
        return a * p.x + b * p.y + c >= 0;
    }
    Line line() const
    {
        return Line(a, b, c);
    }
};

class HalfPlaneIntersector {
private:
    vector <Point> points;
public:
    HalfPlaneIntersector()
    {
        points.push_back(Point(-INF, INF));
        points.push_back(Point(INF, INF));
        points.push_back(Point(INF, -INF));
        points.push_back(Point(-INF, -INF));
    }

    void intersect(const HalfPlane &h)
    {
        vector <Point> result;
        for (unsigned int i = 0; i < points.size(); i++)
        {
            Line a = Line(points[i], points[(i + 1) % points.size()]);
            Segment a_seg = Segment(points[i], points[(i + 1) % points.size()]);
            if (h.contains_point(points[i]))
                result.push_back(points[i]);
            if (a_seg.intersects(h.line()))
                result.push_back(a.intersect(h.line()));
        }
        points = result;
    }

    double perimeter() const
    {
        double res = 0;
        for (unsigned int i = 0; i < points.size(); i++)
            res += Segment(points[i], points[(i + 1) % points.size()]).length();
        return res;
    }
};

// Calculate perimeter of 2 triangle intersection for examle.
int main()
{
    HalfPlaneIntersector hpi;
    for (int i = 0; i < 2; i++)
    {
        Point p1, p2, p3;
        p1.scan();
        p2.scan();
        p3.scan();
        hpi.intersect(HalfPlane(Line(p1, p2), p3));
        hpi.intersect(HalfPlane(Line(p1, p3), p2));
        hpi.intersect(HalfPlane(Line(p2, p3), p1));
    }
    cout << hpi.perimeter();
}
