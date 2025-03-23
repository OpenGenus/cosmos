#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> a[i][j];
        }
    }
    int t;
    std::cin >> t;
    while (t > 0)
    {
        int px, py, qx, qy, sum = 0;
        std::cin >> px >> py >> qx >> qy;
        for (int i = px - 1; i <= qx - 1; ++i)
        {
            for (int j = py - 1; j <= qy - 1; ++j)
            {
                sum += a[i][j];
            }
        }
        std::cout << sum << endl;
    }
    // your code goes here
    return 0;
}
