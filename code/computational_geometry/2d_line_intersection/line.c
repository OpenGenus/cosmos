// C++ Implementation. To find the point of
// intersection of two lines
#include <bits/stdc++.h>
using namespace std;
 
// This pair is used to store the X and Y
// coordinates of a point respectively
#define pdd pair<double, double>
 
// Function used to display X and Y coordinates
// of a point
void displayPoint(pdd P)
{
    cout << "(" << P.first << ", " << P.second
         << ")" << endl;
}
 
pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D)
{
    // Line AB represented as a1x + b1y = c1
    double a1 = B.second - A.second;
    double b1 = A.first - B.first;
    double c1 = a1*(A.first) + b1*(A.second);
 
    // Line CD represented as a2x + b2y = c2
    double a2 = D.second - C.second;
    double b2 = C.first - D.first;
    double c2 = a2*(C.first)+ b2*(C.second);
 
    double determinant = a1*b2 - a2*b1;
 
    if (determinant == 0)
    {
        // The lines are parallel. This is simplified
        // by returning a pair of FLT_MAX
        return make_pair(FLT_MAX, FLT_MAX);
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return make_pair(x, y);
    }
}
 
// Driver code
int main()
{
    pdd A = make_pair(1, 1);
    pdd B = make_pair(4, 4);
    pdd C = make_pair(1, 8);
    pdd D = make_pair(2, 4);
 
    pdd intersection = lineLineIntersection(A, B, C, D);
 
    if (intersection.first == FLT_MAX &&
        intersection.second==FLT_MAX)
    {
        cout << "The given lines AB and CD are parallel.\n";
    }
 
    else
    {
        // NOTE: Further check can be applied in case
        // of line segments. Here, we have considered AB
        // and CD as lines
        cout << "The intersection of the given lines AB "
                "and CD is: ";
        displayPoint(intersection);
    }
 
    return 0;
}
