#include <iostream>
#include <vector>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> tasks;
    for (int i = 1; i <= n; ++i) {
        tasks.push_back(i);
    }
    int done;
    for (int i = 0; i < m; i++) {
        std::cin >> done;
        for (int j = 0; j < tasks.size(); ++j) {
            if (tasks[j] == done) {
                tasks.erase(tasks.begin() + j);
            }
        }
    }
    for (int i = 0; i < tasks.size(); ++i) {
        if (i % 2 == 0) {
            std::cout << tasks[i] << " ";
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < tasks.size(); ++i) {
        if (i % 2 != 0) {
            std::cout << tasks[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
