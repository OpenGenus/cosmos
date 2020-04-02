#include <iostream>

using namespace std;

const long  mod=1000000007;

uint64_t modmul(const uint64_t x, const uint64_t y)
{
	if (x > (1 << 30) && y > (1 << 30))
		return ((x >> 30)*((y << 30) % mod) + y*(x & ((1 << 30) - 1))) % mod;
	uint64_t z = x*y;
	if (z >= mod)
		z %= mod;
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
			ans = (ans + 3) % mod;
		else
			ans = (ans + mod - 3) % mod;
		cout << ans << "\n";
	}

	return 0;
}
