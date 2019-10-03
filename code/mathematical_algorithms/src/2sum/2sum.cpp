//Given an array and a sum, print two numbers from the array that add-up to sum

#include <iostream>
#include <map>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
#define ll long long

map<ll, ll> m;

//Function to find two numbers which add up to sum
void twoSum(ll a[], ll sum, int n)
{
    for (int i = 0; i < n; i++)
        if (m[sum - a[i]])
        {
            cout << "The two numbers are ";
            cout << a[i] << " " << sum - a[i] << endl;
            return;
        }
}

int main()
{
    ll a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(ll);
    ll sum = 8;
    for (int i = 0; i < n; i++)
        m[a[i]] = 1;
    twoSum(a, sum, n);
    return 0;
}
