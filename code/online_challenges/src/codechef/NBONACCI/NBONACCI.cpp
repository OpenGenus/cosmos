#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int n,q;
	cin >> n >> q;

	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	int x = 0;
	int xors[n] = {0};
	for (int i = 0; i < n; i++)
	{
		x = x ^ a[i];
		xors[i] = x;
	}

	while (q > 0)
	{
		int k;
		cin >> k;

		int idx = k % (n + 1);

		if (idx > 0)
			cout << xors[idx - 1]<<"\n";
		else cout << "0\n";

		q = q - 1;
	}

	return 0;
}
