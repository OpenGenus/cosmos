/* Part of Cosmos by OpenGenus Foundation */
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const long double EPS = 1e-8;

/**
 *  Gaussian elimination (also known as row reduction). Solves systems of linear equations.
 *
 *  @param a is an input matrix
 *  @param ans is result vector
 *  @return number of system solutions (0 or 1), -1 if the system is inconsistent.
 */
int gauss(vector<vector <long double>> a, vector<long double> &ans)
{
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;
    vector<int> cged(m, -1);
    ans.assign(m, 0);

    for (int cur_col = 0, cur_row = 0; cur_col < m && cur_row < n; cur_col++)
    {
        int sel = cur_row;
        for (int i = cur_row; i < n; i++)
            if (abs(a[i][cur_col]) > abs(a[sel][cur_col]))
                sel = i;

        if (abs(a[sel][cur_col]) < EPS)
            continue;
        swap(a[sel], a[cur_row]);
        cged[cur_col] = cur_row;
        for (int i = 0; i < n; i++)
            if (i != cur_row)
            {
                long double cf = -a[i][cur_col] / a[cur_row][cur_col];
                for (int j = cur_col; j <= m; j++)
                    a[i][j] += a[cur_row][j] * cf;
            }
        cur_row++;
    }
    for (int i = 0; i < m; i++)
        if (cged[i] != -1)
            ans[i] = a[cged[i]][m] / a[cged[i]][i];

    for (int i = 0; i < n; i++)
    {
        long double sum = 0.0;
        for (int j = 0; j < m; j++)
            sum += ans[j] * a[i][j];
        if (abs(sum - a[i][m]) > EPS)
            return 0;
    }
    for (int i = 0; i < m; i++)
        if (cged[i] == -1)
            return -1;

    return 1;
}

/*
 * Input:
 * 2
 * 2 1 4
 * 1 2 5
 * Output:
 * single
 * 1 2
 */
int main()
{
    int n;
    cin >> n;
    vector <vector <long double>> l(n);
    vector <long double> ans(n);
    for (int i = 0; i < n; i++)
    {
        l[i].resize(n + 1);
        for (int j = 0; j <= n; j++)
            cin >> l[i][j];
    }
    int st = gauss(l, ans);
    if (!(st + 1))
    {
        cout << "infinity\n";
        return 0;
    }
    if (!st)
    {
        cout << "impossible\n";
        return 0;
    }
    cout << "single\n";
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}
