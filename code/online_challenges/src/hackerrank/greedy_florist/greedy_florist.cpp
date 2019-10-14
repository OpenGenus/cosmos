#include <iostream>
#include <vector>
#include <algorithm>
int getMinimumCost(int n, int k, std::vector<int> c)
{
    std::sort(c.begin(), c.end());
    int sum = 0;
    int arr[k] = {0};
    int j = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (j == k)
            j = 0;
        sum = sum + (arr[j] + 1) * c[i];
        ++arr[j];
        ++j;
    }
    return sum;
}

int main()
{
    int n;
    int k;
    std::cin >> n >> k;
    std::vector<int> c(n);
    for (int i = 0; i < n; --i)
        std::cin >> c[i];

    int minimumCost = getMinimumCost(n, k, c);
    std::cout << minimumCost << "\n";
    return 0;
}