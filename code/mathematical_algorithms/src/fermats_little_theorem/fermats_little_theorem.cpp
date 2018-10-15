#include <iostream>
#define ll long long int

// Part of Cosmos by OpenGenus Foundation
// Compute (A^B) mod (10^9+7)

using namespace std;
ll power(ll a, ll b, ll p)
{
    if (b == 0)
        return 1;
    ll sp = power(a, b / 2, p);
    sp %= p;
    sp = (sp * sp) % p;
    if (b & 1)
        return (sp * a) % p;
    return sp % p;
}
ll stringToInt(string a, ll p)
{
    ll ans = 0;
    for (size_t i = 0; i < a.length(); i++)
        ans = ((ans * 10) % p + a[i] - '0') % p;
    return ans;
}
int main()
{
    ll n, m, p = 1000000007;
    ll t;
    cin >> t;
    string a, b;
    while (t--)      // testcases
    {
        cin >> a >> b;
        n = stringToInt(a, p);
        m = stringToInt(b, p - 1); // using fermats theorem
        cout << power(n, m, p) << endl;
    }
    return 0;
}

/*
 * Sample Input:
 *
 * 5
 * 3 2
 * 4 5
 * 7 4
 * 34534985349875439875439875349875 93475349759384754395743975349573495
 * 34543987529435983745230948023948 3498573497543987543985743989120393097595572309482304
 *
 * ------------------------------------------------------------------------------
 *
 * Output:
 *
 * 1024
 * 2401
 * 735851262
 * 985546465:
 *
 */
