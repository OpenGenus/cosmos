//z function

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> zfunc(1000000);

void z_function(string s) {
	int n = (int) s.size(), l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r)
			zfunc[i] = min(r - i + 1,zfunc[i - l]);

		while(zfunc[i] + i < n && s[zfunc[i]] == s[zfunc[i] + i])
			zfunc[i]++;

		if (i + zfunc[i] - 1 > r) {
			l = i;
			r = i + zfunc[i] - 1;
		}
	}
}

int main() {
	string shave, ssearch, current;
	cin >> shave >> ssearch;
	current = ssearch + '$' + shave;
	z_function(current);
	for (int i = (int) ssearch.size() - 1; i < (int) current.size(); i++) {
		if (zfunc[i] == (int) ssearch.size()) {
			cout << i - (int) ssearch.size() << " ";
		}
	}
	return 0;
}
