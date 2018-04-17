/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * BY:- https://github.com/alphaWizard
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int max_subarray_sum(const vector<int>& ar)
{
    int msf = ar[0], mth = max(ar[0], 0);
    size_t p = 0;
    if (ar[0] < 0)
        ++p;
    int maxi = ar[0];
    for (size_t i = 1; i < ar.size(); i++)
    {
        maxi = max(maxi, ar[i]);
        if (ar[i] < 0)
            ++p;           // for handing case of all negative array elements

        mth += ar[i];
        if (mth > msf)
            msf = mth;
        if (mth < 0)
            mth = 0;
    }
    return (p != ar.size()) ? msf : maxi;
}

int main()
{

    cout << max_subarray_sum({-3, 2, -1, 4, -5}) << '\n';   // Expected output: 5
    cout << max_subarray_sum({-1, -2, -3, -4, -5}) << '\n'; // Expected output: -1
    return 0;
}
