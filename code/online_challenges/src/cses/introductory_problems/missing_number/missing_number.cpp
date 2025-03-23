/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
using namespace std;

#define ll long long int

int main() 
{
    ll n, sum = 0, temp;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> temp;
        sum += temp;
    }
    cout << (n * (n + 1) / 2) - sum << endl;
	return 0;
}