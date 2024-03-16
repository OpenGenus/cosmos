#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPerfectSquare(int n)
{
    // If it's 1 then return true
    if (n < 2)
        return true;

    // Initializing Start, Mid, and End pointer 

    int s = 1,
    e = n / 2; // initializing end pointer with n/2 since [ 1 < sqrt(n) < n/2 where n != 1 ]
    long long int m;

    //  taking m as sqrt of n 
    
    
    while (s <= e)
    {
        m = (s + e) / 2; // updating mid 

        if (m * m == n)
        {
            return true;
        }
        else if (m * m > n) 
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    cout<<isPerfectSquare(n);

    return 0;
}
