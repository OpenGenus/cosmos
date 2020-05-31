#include <iostream>
#include <vector>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
long long tiling(int n)
{
    vector<long long int> tile(n + 1);

    tile[0] = 1;
    tile[1] = 1;
    tile[2] = 2;
    for (int i = 3; i <= n; i++)
        tile[i] = tile[i - 1] + tile[i - 2];
    return tile[n];
}

int main()
{
    int n;
    cout << "enter the value of n\n";
    cin >> n;
    cout << "total ways to arrange the tiles is " << tiling(n);
}
