#include <iostream>
#include <vector>

int main() {
    std::vector<int> m = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int t;
    std::cin >> t;
    while (t--) {
        long long int a, b, sum = 0;
        std::cin >> a >> b;
        a += b;
        while (a > 0) {
            sum += m[a % 10];
            a /= 10;
        }
        std::cout << sum << "\n";
    }
}
