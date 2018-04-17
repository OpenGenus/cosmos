// A C++ program to find the sum of all the primes not greater than given N.
// Constraints:  1<=N<=10^6
// Constraints : 1<=t<=10^6
// Part of Cosmos by OpenGenus Foundation

#include <iostream>
typedef long long int ll;
using namespace std;

int a[1000005] = {0}; ll b[1000005] = {0};
void sieve(int n)
{
    ll s = 0;
    int i;
    for (i = 2; i * i <= n; i++)
    {
        if (a[i] == 0)
        {
            s += i;
            for (int j = 2 * i; j <= n; j += i)
                a[j] = 1;
        }
        b[i] = s;
    }
    int j;
    for (j = i; j <= n; j++)
    {
        if (a[j] == 0)
            s += j;
        b[j] = s;
    }
}

int main()
{
    sieve(1000000); // precomputing the summation of all primes upto n less than or equal to 10^6
    int t;
    cin >> t; // No. of test cases as input
    while (t--)
    {
        int n;
        cin >> n; // Given input number n
        cout << b[n] << endl;   // b[n] gives summation of all primes less than or equal to n.
    }
}
