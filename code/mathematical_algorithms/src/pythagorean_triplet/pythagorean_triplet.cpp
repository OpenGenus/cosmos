// A Pythagorean triplet is a set of three natural numbers, a<b<c, for which a^2 + b^2 = c^2
// Given N, Check if there exists any Pythagorean triplet for which a+b+c=N
//Find maximum possible value of abc among all such Pythagorean triplets, If there is no such Pythagorean triplet print  -1.

#include <iostream>

using namespace std;
#define opt std::ios_base::sync_with_stdio(false)
typedef long long int ll;

int main()
{
    opt;
    int t;
    cin >> t;
    while (t--)
    {
        double n;
        ll m = 0;
        cin >> n;
        double a;
        for (a = 1; a < n / 2; a++)    // keeping a and n constant and using given two equations, we will get the value of b and c in terms of n and a
        {                     // from expression of b, we can see that a should be less than n/2
            double b, c;
            b = ((n * n) - 2 * a * n) / (2 * (n - a));          //solving the given 2 equations, we will get this expression of b
            c = ((n - a) * (n - a) + (a * a)) / (2 * (n - a));    //solving the given 2 equations, we will get this expression of c
            int p = int(b), q = int(c);
            if (b == p && c == q && ((a * a + b * b) == (c * c)) )
                m = max(m, ll(ll(a) * p * q));
        }
        (m != 0) ? cout << m << endl : cout << -1 << endl;
    }
}
