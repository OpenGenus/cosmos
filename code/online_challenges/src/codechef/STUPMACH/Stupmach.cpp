#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        long long int a[n], max = 1000000000, ans = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (a[i] < max) {
                max = a[i];
            }
            ans += max;
        }
        std::cout << ans << "\n";
    }
    return 0;
}
 /*
 TEST CASE
INPUT
1
3
2 1 3
OUTPUT
4
 */
