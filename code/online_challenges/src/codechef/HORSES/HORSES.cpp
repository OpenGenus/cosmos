#include <cstdlib>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int a[n];
        for (int j = 0; j < n; ++j) {
            std::cin >> a[j];
        }
        int min = abs(a[0] - a[1]);
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (abs(a[j] - a[k]) < min) {
                    min = abs(a[j] - a[k]);
                }
            }
        }
        std::cout << min << "\n";
    }
    return 0;
}
/*
Input:
1
5
4 9 1 32 13

Output:
3
*/
