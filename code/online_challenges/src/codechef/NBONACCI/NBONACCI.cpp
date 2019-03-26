#include <bits/stdc++.h>
using namespace std;

int main () {

	int n,q;
	cin >> n >> q;

	int a[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i];

	int x = 0;
	int xors[n] = {0};

	for (int i = 0; i < n; ++i)
	{
		x = x ^ a[i];
		xors[i] = x;
	}

	while (q--)
	{
		int k;
		cin >> k;
		int idx = k % (n + 1);

		if (idx > 0)
			cout << xors[idx - 1] << "\n";
		else cout<< "0\n";
	}
	
	return 0;
}