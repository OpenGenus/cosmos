#include <algorithm>
#include <iostream>
#include <vector>

bool istrue(std::vector<int> a, std::vector<int> c) {
    std::pair<int, int> pairt[3];
    bool x = true;
    int i;
    for (i = 0; i < 3; ++i) {
        pairt[i].first = a[i];
        pairt[i].second = c[i];
    }
    std::sort(pairt, pairt + 3);
    for (i = 0; i < 2; ++i) {
        if (pairt[i].first == pairt[i + 1].first) {
            if (pairt[i].second != pairt[i + 1].second) {
                x = false;
                break;
            }
        }
        if (pairt[i].second > pairt[i + 1].second) {
            x = false;
            break;
        }
        if (pairt[i].second == pairt[i + 1].second) {
            if (pairt[i].first != pairt[i + 1].first) {
                x = false;
                break;
            }
        }
    }
    return x;
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::vector<int> a(3), c(3);
        int i;
        for (i = 0; i < 3; ++i) {
            std::cin >> a[i];
        }
        for (i = 0; i < 3; ++i) {
            std::cin >> c[i];
        }
        bool x = istrue(a, c);
        if (x) {
            std::cout << "FAIR" << std::endl;
        } else {
            std::cout << "NOT FAIR" << std::endl;
        }
    }
}
