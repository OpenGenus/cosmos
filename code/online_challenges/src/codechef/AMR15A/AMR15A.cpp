#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	int count = 0;
	for (auto &e : a)
	{
		cin >> e;
		if (e % 2 == 0)
			++count;
	}
	if (count > n / 2)
		cout << "READY FOR BATTLE\n";
	else
		cout << "NOT READY\n";

	return 0;
}
