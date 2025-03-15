#include <bits/stdc++.h>
using namespace std;
#define int long long int
main()
{
    //Input a number and let call it x
    int x;
    cin >> x;
    // Now check whether the bitwise and of x and x-1 is 0. If it is zero, then it's a power of 2 because if x is a power of 2
    //then it has only one rightmost set bit and all the bits to the right of it are zero and x-1 will have all the bits
    //complementary to x
    if (x != 0 && (x & (x - 1)) == 0)
        cout << "Yes it is a power of 2"
             << "\n";
    else
        cout << "No it is not a power of 2"
             << "\n";
}
