/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
using namespace std;

int main()
{
    int n, m, a[502] = {}, b[502] = {}, d[502][502] = {}, z = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        for (int j = 1; j <= m; j++)
        {
            d[i][j] = d[i - 1][j];
            if (b[j] < a[i])
                k = max(k, d[i - 1][j]);
            if (b[j] == a[i])
                d[i][j] = max(d[i - 1][j], k + 1);
            z = max(z, d[i][j]);
        }
    }
    cout << z << '\n';
}
