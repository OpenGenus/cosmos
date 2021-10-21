#include<bits/stdc++.h>
using namespace std;
#define iPair pair<int, int>
set<iPair> hull;// stores the final points to create the convex hull

int findSide(iPair p1, iPair p2, iPair p)// returns the side of the hull joined points p1 and p2
{
    int val = (p.second - p1.second) * (p2.first - p1.first) -
              (p2.second - p1.second) * (p.first - p1.first);
  
    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}

int line_distance(iPair p1, iPair p2, iPair p)
{
    return abs ((p.second - p1.second) * (p2.first - p1.first) -
               (p2.second - p1.second) * (p.first - p1.first));
}

void quickHull(iPair arr[], int size, iPair p1, iPair p2, int side)
{
    int ind = -1;
    int max_dist = 0;

    for (int i=0; i<size; i++)
    {
        int temp = line_distance(p1, p2, arr[i]);
        if (findSide(p1, p2, arr[i]) == side && temp > max_dist)
        {
            ind = i;
            max_dist = temp;
        }
    }

    if (ind == -1)
    {
        hull.insert(p1);
        hull.insert(p2);
        return;
    }

    quickHull(arr, size, arr[ind], p1, -findSide(arr[ind], p1, p2));
    quickHull(arr, size, arr[ind], p2, -findSide(arr[ind], p2, p1));
}
  
void print(iPair arr[], int size)
{
    if (size < 3)
    {
        cout << "Convex hull not possible\n";
        return;
    }
  
    int min_x = 0, max_x = 0;
    for (int i=1; i<size; i++)
    {
        if (arr[i].first < arr[min_x].first)
            min_x = i;
        if (arr[i].first > arr[max_x].first)
            max_x = i;
    }
  
    quickHull(arr, size, arr[min_x], arr[max_x], 1);
    quickHull(arr, size, arr[min_x], arr[max_x], -1);
  
    cout << "The Convex Hull points are:\n";
    while (!hull.empty())
    {
        cout << "(" <<( *hull.begin()).first << ", "
             << (*hull.begin()).second << ") ";
        hull.erase(hull.begin());
    }
}

int main()
{
    iPair arr[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
               {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int size = sizeof(arr)/sizeof(arr[0]);
    print(arr, size);
    return 0;
}


// OUTPUT
// The Convex Hull points are:
// (0, 0) (0, 3) (3, 1) (4, 4)

// Code curated by Subhadeep Das(username:- Raven1233)