#include <iostream>
using namespace std;
long long powmod(long long base, long long exp, long long mod)
{
    long long ans = 1 % mod;
    while (exp > 0)
    {
        if (exp & 1)
            ans = (ans * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return ans;
}
int main()
{
    long long base, exp, mod;
    cin >> base >> exp >> mod;
    cout << powmod(base, exp, mod) << endl;
    return 0;
}
