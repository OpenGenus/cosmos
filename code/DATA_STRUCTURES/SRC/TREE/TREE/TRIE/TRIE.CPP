#include <cstdio>
#include <string>
#include <iostream>

// Part of Cosmos by OpenGenus
using namespace std;
#define mod 1000000007
#define all(v) v.begin(), v.end_()
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
    {
    }
    register long long a = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        a = (a << 3) + (a << 1) + c - '0';
    return a;
}
const ll N = 100009;
int n, i, j, sz;
string a;
ll next_[27][N], end_[N];
void add(string a)
{
    int v = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        int c = a[i] - 'a';
        if (next_[c][v] == -1)
            v = next_[c][v] = ++sz;
        else
            v = next_[c][v];
    }
    ++end_[v];
}
bool search(string a)
{
    int v = 0;
    for (i = 0; i < (int)a.size(); i++)
    {
        int c = a[i] - 'a';
        if (next_[c][v] == -1)
            return false;
        v = next_[c][v];
    }
    return end_[v] > 0;
}
int main()
{
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    rep(i, 0, 27) for (int j = 0; j < N; j++)
        next_[i][j] = -1;
    rep(i, 0, n) cin >> a, add(a);
    cin >> n;
    while (n--)
    {
        cin >> a;
        cout << search(a) << endl;
    }
    return 0;
}
