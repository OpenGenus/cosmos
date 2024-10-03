#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    int n, k, c = 0;
    std::cin >> n >> k;
    std::vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        std::cin >> temp;
        v.push_back(temp);
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; ++i)
    {
        if (v[i] - v[i + 1] == k || v[i + 1] - v[i] == k)
            ++c;
        else if (v[i] - v[i + 1] < k || v[i + 1] - v[i] < k)
        {
            int temp = 1;
            while (abs(v[i] - v[i + temp]) <= k)
            {
                if (v[i] - v[i + temp] == k || v[i + temp] - v[i] == k)
                {
                    ++c;
                    break;
                }
                ++temp;
            }
        }
    }
    std::cout << c;

    return 0;
}