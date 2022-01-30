#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k, x, sum = 0;
        std::cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            std::cin >> x;
            sum += x;
        }
        sum %= k;
        std::cout << sum << "\n";
    }
}
