#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k, ans = 0;
        std::cin >> n;
        int a[100];
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::cin >> k;
        for (int i = 0; i < n; ++i) {
            ans += (a[k - 1] > a[i]);
        }
        std::cout << ans + 1 << '\n';
    }

    return 0;
}
