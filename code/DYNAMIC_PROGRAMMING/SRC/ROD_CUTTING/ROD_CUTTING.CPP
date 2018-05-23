#include <iostream>
#include <vector>
// Part of Cosmos by OpenGenus Foundation
// Use bottom-up DP, O(n^2) time, O(n) space.
using namespace std;
int rodCutting(int rod_length, vector<int> prices)
{
    vector<int> best_price(rod_length + 1, 0);
    best_price[0] = 0;
    for (int i = 1; i <= rod_length; ++i)
    {
        int maximum_price = INT8_MIN;
        for (int j = 1; j <= i; ++j)
            maximum_price = max(maximum_price, prices[j - 1] + best_price[i - j]);
        best_price[i] = maximum_price;
    }
    return best_price[rod_length];
}

int main()
{
    cout << rodCutting(8, {1, 5, 8, 9, 10, 17, 17, 20, 24, 30}) << endl; // should be 22 (one length 2, another length 6)
    cout << rodCutting(10, {1, 5, 8, 9, 10, 17, 17, 20, 24, 30}) << endl; // should be 30
    return 0;
}
