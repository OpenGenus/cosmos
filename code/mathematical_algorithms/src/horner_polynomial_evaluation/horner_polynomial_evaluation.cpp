#include <iostream>
#include <vector>

using namespace std;
// Part of Cosmos by OpenGenus Foundation

typedef long long ll;
typedef vector<ll> Poly;

// evaluate p(x) in linear time
ll evaluate(const Poly& p, ll x)
{
    ll ret = 0;
    for (int i = p.size() - 1; i >= 0; --i)
        ret = ret * x + p[i];
    return ret;
}

int main()
{
    // polynomial degree
    int n;
    scanf("%d", &n);
    Poly poly(n + 1);

    // reads coefficients from lowest to highest power
    for (int i = 0; i <= n; ++i)
        scanf("%lld", &poly[i]);

    // number of queries and x to evaluate
    int q, x;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &x);
        printf("%lld\n", evaluate(poly, x));
    }

    return 0;
}
