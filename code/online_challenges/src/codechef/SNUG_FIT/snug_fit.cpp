#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, sum = 0;
        cin >> n;
        vector<int> a(n), b(n);
        for (i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (i = 0; i < n; ++i) {
            sum += min(a[i], b[i]);
        }
        cout << sum << "\n";
    }
}
