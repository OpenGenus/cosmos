/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <cmath>

using namespace std;

// Structure of a point in 2D plane
struct Point
{
    int x;
    int y;
};
 
// A utility function to find distance between two points in a plane
double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
                (p1.y - p2.y)*(p1.y - p2.y));
}
 
// The cost is considered as the perimeter (sum of lengths of all edges) of the triangle
double cost(Point points[], int i, int j, int k)
{
    Point p1 = points[i], p2 = points[j], p3 = points[k];
    return dist(p1, p2) + dist(p2, p3) + dist(p3, p1);
}

double minCostPolygon(Point points[], int n)
{
   // There must be at least 3 points to form a triangle
   if (n < 3)
      return 0;
 
   // table[i][j] stores cost of triangulation of points from i to j.
   double table[n][n];

   static const int MAX = 1000000.0;
 
   for (int gap = 0; gap < n; gap++)
   {
      for (int i = 0, j = gap; j < n; i++, j++)
      {
          if (j < i+2)
             table[i][j] = 0.0;
          else
          {
              table[i][j] = MAX;
              for (int k = i+1; k < j; k++)
              {
                double val = table[i][k] + table[k][j] + cost(points, i, j, k);
                if (table[i][j] > val)
                     table[i][j] = val;
              }
          }
      }
   }
   return table[0][n-1];
}

int main()
{
    Point points[] = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}};
    int n = sizeof(points)/sizeof(points[0]);
    cout<<minCostPolygon(points, n);
    return 0;
}