#include <iostream>
#include <set>
typedef long long int ll;

ll solve() {
    std::set<ll> ss;
    ll n, a, b, c, ans1, ans2;
    std::cin >> n >> a >> b >> c;
    for (ll i = 0; i < n; ++i) {
        ll x;
        std::cin >> x;
        ss.insert(x);
    }
    if (n == 1) {
        auto it = ss.begin();
        ans1 = abs((*it) - a) + c + abs((*it) - b);
        std::cout << ans1 << "\n";
        return;
    }
    auto it = ss.begin();
    if (b > (*it)) {
        while ((*it) < b) {
            ++it;
        }
        --it;
    } else {
        it = ss.lower_bound(b);
    }
    ans1 = abs((*it) - a) + c + abs((*it) - b);
    ++it;
    ans2 = abs((*it) - a) + c + abs((*it) - b);
    return std::min(ans1, ans2);
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cout << solve() << std::endl;
    }
}

