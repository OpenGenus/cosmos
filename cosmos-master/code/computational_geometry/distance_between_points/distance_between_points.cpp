#include <iostream>
#include <cmath>

typedef std::pair<double, double> point;

#define x first
#define y second

double calcDistance (point a, point b) {
  return sqrt( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) );
}

int main () {
  point a, b, c;
  std::cin >> a.x >> a.y >> b.x >> b.y;
  std::cout << calcDistance(a, b);
}
