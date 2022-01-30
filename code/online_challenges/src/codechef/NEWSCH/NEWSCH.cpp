#include <iostream>

#include <cstring>

using namespace std;

#define MOD 1000000007

uint64_t modmul(const uint64_t x, const uint64_t y)
{
	if (x > (1 << 30) && y > (1 << 30))
		return ((x >> 30)*((y << 30) % MOD) + y*(x & ((1 << 30) - 1))) % MOD;
	uint64_t z = x*y;
	if (z >= MOD)
		z %= MOD;
	return z;
}

uint64_t modpow(uint64_t base, int exp)
{
	uint64_t result = 1;
	for (;;)
	{
		if (exp & 1)
			result = modmul(result, base);
		exp >>= 1;
		if (!exp)
			break;
		base = modmul(base, base);
	}

	return result;
}

int main()
{
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int n;
		cin >> n;
		uint64_t ans = modpow(3, n);
		if (n % 2 == 0)
			ans = (ans + 3) % MOD;
		else
			ans = (ans + MOD - 3) % MOD;
		cout << ans << endl;
	}

	return 0;
}
