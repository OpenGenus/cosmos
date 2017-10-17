/*
Part of Cosmos by OpenGenus Foundation

BY:- https://github.com/alphaWizard

*/

#include <iostream>
#include <vector>

using namespace std;

int max_subarray_sum(const vector<int>& ar)
{
    int msf = ar[0], mth = max(ar[0], 0);
    int p = 0;
    if(ar[0] < 0) ++p;
    int maxi = ar[0];
    for(int i = 1; i < ar.size(); i++)
    {
        maxi = max(maxi, ar[i]);
        if(ar[i] < 0) ++p; // for handing case of all negative array elements
       
        mth += ar[i];
        if(mth > msf) msf = mth;
        if(mth < 0) mth = 0;
    }
    return (p != ar.size()) ? msf : maxi;
}

int main() {
    int t;  // t number of test cases entered 
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //enter no. of terms
        vector<int> ar(n);
        for(int i = 0; i < n; ++i)
            cin >> ar[i];  //enter n elements of array
        cout << maxsubarraysum(ar) << "\n";
    }
    return 0;
}
