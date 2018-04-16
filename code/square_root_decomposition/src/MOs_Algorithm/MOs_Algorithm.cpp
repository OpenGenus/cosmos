//Time Complexity : O((n+q)*sqrt(n))

#include <bits/stdc++.h>
#include <cmath>

/* Part of Cosmos by OpenGenus Foundation */


#define ll long long int
#define mod 1000000007
#define show(a) for (i = 0; i < a.size(); i++) cout << a[i] << " ";
#define fi first
#define se second
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long int>
#define pb push_back
#define pi pair<int, int>
#define si set<int>
#define sll set<ll>
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int>>
#define mp make_pair
#define fast_io() cin.sync_with_stdio(false); cout.sync_with_stdio(false);
#define long_zero 0ll
#define long_one 1ll
inline int sbt(int x)
{
    return __builtin_popcount(x);
}
using namespace std;
int freq[1111111];
int BLOCK;
//Mo Sorting
bool f(pair<int, pi> a, pair<int, pi> b)
{
    if (a.se.fi / BLOCK == b.se.fi / BLOCK)
        return a.se.se > b.se.se;
    return a.se.fi / BLOCK > b.se.fi / BLOCK;
}
int main()
{
    system("cls");
    //fast_io()
    int n;
    scanf("%d", &n);
    int a[n + 3];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int l, r, s = 0, e = 0, Q;
    vector<pair<int, pi>>q;
    scanf("%d", &Q);
    //block size:SQRT(N)
    BLOCK = floor(sqrt(1.0 * double(n)));
    for (int i = 0; i < Q; i++)
    {
        scanf("%d%d", &l, &r);
        q.pb(mp(i, mp(l - 1, r - 1)));
    }
    int v[Q + 4], ans = 0;
    sort(q.begin(), q.end(), f);  //f is comparator
    for (int i = 0; i < Q; i++)
    {
        l = q[i].se.fi;
        r = q[i].se.se;
        while (s < l)
        {
            freq[a[s]]--;
            if (!freq[a[s]])
                ans--;
            s++;
        }
        while (s > l)
        {
            freq[a[s - 1]]++;
            if (freq[a[s - 1]] == 1)
                ans++;
            s--;
        }
        while (e <= r)
        {
            freq[a[e]]++;     // mantains frequency
            if (freq[a[e]] == 1)
                ans++;
            e++;
        }
        while (e > r + 1)
        {
            freq[a[e - 1]]--;
            if (freq[a[e - 1]] == 0)
                ans--;
            e--;
        }

        v[q[i].fi] = ans;
    }
    for (int i = 0; i < Q; i++)
        printf("%d\n", v[i]);

    return 0;

}
