#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int MOD2 = (int) 1e8 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";

//Given a number N, find sum of all GCDs that can be formed by selecting all the pairs from 1 to N.

const int N = 12;
int phi[N + 1];
int prime[N + 1];
long long G[N + 1];

int main() {
    // Compute phi[n]
    for (int p = 1; p <= N; ++ p) phi[p] = p;
    for (int p = 2; p <= N; ++ p)
        if (phi[p] == p)
           for (int n = p; n <= N; n += p)
               phi[n] = phi[n]/p*(p-1);

    // Compute prime[n] -> Largest prime that divides n
    for (int p = 1; p <= N; ++ p) prime[p] = 0;
    for (int p = 2; p <= N; ++ p)
        if (prime[p] == 0)
           for (int n = p; n <= N; n += p) prime[n] = max(prime[n], p);

    G[1] = 1;
    for (int n = 2; n <= N; ++ n) {
        int p = 1;
        int k = 0;
        while (p <= n/prime[n] && n % (p * prime[n]) == 0) {
              p *= prime[n];
              ++ k;
        }
        G[n] = ((k+1)*p - k*p/prime[n]) * G[n/p];
    }

    G[1] = G[1] - 1;
    for (int n = 2; n <= N; ++ n) G[n] += G[n-1] - n;
    cout << G[N] << endl;
}


