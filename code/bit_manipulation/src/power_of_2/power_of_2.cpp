/* Part of Cosmos by OpenGenus Foundation */
/* Created by Shubham Prasad Singh on 12/10/2017 */

/* Check if a number is a power of 2 */
#include <iostream>
using namespace std;
typedef long long ll;
bool isPowerOf2(ll n)
{
    return n && (!(n & (n - 1)));
}
int main()
{
    ll n;
    cout << "Enter a number\n";
    cin >> n;
    if (isPowerOf2(n))
        cout << "Is a power of 2" << endl;
    else
        cout << "Not a power of 2" << endl;
    return 0;
}
