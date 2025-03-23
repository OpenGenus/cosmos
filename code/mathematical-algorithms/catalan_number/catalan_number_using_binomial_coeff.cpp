
/* Using Binomial Coefficient 
   Catn = (1/n+1)*2nCn       */


#include<iostream>
using namespace std;
 

unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{
    unsigned long int res = 1;
 
    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
 
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}
 
unsigned long int catalan(unsigned int n)
{

    unsigned long int tmp = binomialCoeff(2*n, n);
 
    return tmp/(n+1);
}
 
 
int main()
{
    for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";
    return 0;
}


// Time Complexity: O(n)



