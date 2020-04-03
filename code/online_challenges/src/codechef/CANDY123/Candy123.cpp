#include <iostream>

void solve() {
    int a, b, i = 1, limak = 0, bob = 0;
    std::cin >> a >> b;
    while (true) {
        if (i & 1) {
            limak += i;
        } else {
            bob += i;
        }
        if (limak > a) {
            std::cout << "Bob\n";
            return;
        }
        if (bob > b) {
            std::cout << "Limak\n";
            return;
        }
        ++i;
    }
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
