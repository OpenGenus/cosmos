#include <iostream>
typedef long long int ll;

int main() {
    ll n;
    std::cin >> n;
    ll sum1 = 0, sum2;
    for (ll i = 0; i < n; ++i) {
        ll temp;
        std::cin >> temp;
        sum1 += temp;
    }
    sum2 = n * (n + 1) / 2;
    if (sum2 == sum1) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
