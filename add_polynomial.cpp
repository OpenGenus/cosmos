// Simple C++ program to add two polynomials
#include <iostream>
using namespace std;
 
// A utility function to return maximum of two integers
int max(int m, int n) {  return (m > n)? m: n; }
 
// A[] represents coefficients of first polynomial
// B[] represents coefficients of second polynomial
// m and n are sizes of A[] and B[] respectively
int *add(int A[], int B[], int m, int n)
{
   int size = max(m, n);
   int *sum = new int[size];
 
   // Initialize the porduct polynomial
   for (int i = 0; i<m; i++)
     sum[i] = A[i];
 
   // Take ever term of first polynomial
   for (int i=0; i<n; i++)
       sum[i] += B[i];
 
   return sum;
}
 
// A utility function to print a polynomial
void printPoly(int poly[], int n)
{
    for (int i=0; i<n; i++)
    {
       cout << poly[i];
       if (i != 0)
        cout << "x^" << i ;
       if (i != n-1)
       cout << " + ";
    }
}
 
// Driver program to test above functions
int main()
{
    // The following array represents polynomial 5 + 10x^2 + 6x^3
    int A[] = {5, 0, 10, 6};
 
    // The following array represents polynomial 1 + 2x + 4x^2
    int B[] = {1, 2, 4};
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);
 
    cout << "First polynomial is \n";
    printPoly(A, m);
    cout << "\nSecond polynomial is \n";
    printPoly(B, n);
 
    int *sum = add(A, B, m, n);
    int size = max(m, n);
 
    cout << "\nsumuct polynomial is \n";
    printPoly(sum, size);
 
    return 0;
}