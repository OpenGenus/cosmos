/*
 * Complexity = O(length of string)
 * s = aaabaab => z[] = {-1,2,1,0,2,1,0}
 * s = aaaaa => z[] = {-1,4,3,2,1}
 * s = abacaba => z[] = {-1,0,1,0,3,0,1}
 * Part of Cosmos by OpenGenus Foundation
 */
#include <iostream>
using namespace std;
#define mod 1000000007
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for (i = (ll)a; i < (ll)b; i++)
#define revrep(i, a, b) for (i = (ll)a; i >= (ll)b; i--)
#define strep(it, v) for (it = v.begin(); it != v.end_(); ++it)
#define ii pair<ll, ll>
#define MP make_pair
#define pb push_back
#define f first
#define se second
#define ll long long int
#define vi vector<ll>
ll modexp(ll a, ll b)
{
    ll res = 1; while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);  b /= 2;
    }
    return res;
}
#define rs resize
long long readLI()
{
    register char c;  for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar())
        ;
    register long long a = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        a = (a << 3) + (a << 1) + c - '0';
    return a;
}
const int N = 100009;
string a;
ll i, z[N];
void z_function(string s)
{
    ll l = 0, r = 0, n = s.length();
    rep(i, 1, n){
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n and s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> a;
    z[0] = -1; //Not possible of zero length
    z_function(a);
    rep(i, 0, a.length()) cout << z[i] << " ";
    return 0;
}
