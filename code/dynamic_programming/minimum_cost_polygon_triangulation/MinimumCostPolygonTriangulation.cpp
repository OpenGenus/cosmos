/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
 
// A utility function to find distance between two points in a plane
double dist(pair <int, int> p1, pair <int, int> p2)
{
    return sqrt((p1.first - p2.first)*(p1.first - p2.first) +
                (p1.second - p2.second)*(p1.second - p2.second));
}
 
// The cost is considered as the perimeter (sum of lengths of all edges) of the triangle
double cost(vector <pair <int, int> > points, int i, int j, int k)
{
    pair <int, int> p1 = points[i], p2 = points[j], p3 = points[k];
    return dist(p1, p2) + dist(p2, p3) + dist(p3, p1);
}

double minCostPolygon(vector <pair <int, int> > points, int n)
{
   // There must be at least 3 points to form a triangle
   if (n < 3)
      return 0;
 
   // table[i][j] stores cost of triangulation of points from i to j.
   double table[n][n];

   static const double MAX = 1000000.0;
 
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
    vector <pair <int, int> > points;
    points.push_back(make_pair(0, 0));
    points.push_back(make_pair(1, 0));
    points.push_back(make_pair(2, 1));
    points.push_back(make_pair(1, 2));
    points.push_back(make_pair(0, 2));
    int n = 5;
    cout<<minCostPolygon(points, n);
    return 0;
}