#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, i, sum = 0;
        std::cin >> n;
        std::vector<int> a(n), b(n);
        for (i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (i = 0; i < n; ++i) {
            std::cin >> b[i];
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        for (i = 0; i < n; ++i) {
            sum += std::min(a[i], b[i]);
        }
        std::cout << sum << "\n";
    }
}
