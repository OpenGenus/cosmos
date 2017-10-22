#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

double distanceBetweenPoints(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main() {
    Point a, b;

    printf("First point (x y): ");
    scanf("%lg %lg", &a.x, &a.y);
    printf("Second point (x y): ");
    scanf("%lg %lg", &b.x, &b.y);

    printf("%lg", distanceBetweenPoints(a, b));

    return 0;
}
