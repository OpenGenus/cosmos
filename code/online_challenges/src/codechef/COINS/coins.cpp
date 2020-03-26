#include <iostream>
#include <unordered_map>

#define lli long long int
std::unordered_map<lli, lli> mpp;

lli check(lli n)
{
    if (n == 0) {
        mpp[0] = 0;
        return 0;
    }
    if (mpp[n] != 0)
        return mpp[n];
    else {
        mpp[n] = check(n / 2) + check(n / 3) + check(n / 4);
        mpp[n] = std::max(n, mpp[n]);
        return mpp[n];
    }
}

int main()
{
    for (lli n; std::cin >> n;) {
        lli d = check(n);

        std::cout<< std::max(n, d) << "\n";
    }
    return 0;
}
