#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    int m;
    int a;
    int b;
    int k;

    std::cin >> n >> m;
    std::vector<std::pair<int, int> > v;

    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b >> k;
        v.push_back(std::make_pair(a, k));
        v.push_back(std::make_pair(b + 1, -1 * k));
    }

    long mx = 0, sum = 0;
    std::sort(v.begin(), v.end());

    for (int i = 0; i < 2 * m; ++i) {
        sum += v[i].second;
        mx = std::max(mx, sum);
    }

    std::cout << mx << "\n";
    return 0;
}
