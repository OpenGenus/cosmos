#include <bits/stdc++.h>
using namespace std;

#define ff(i, a, b) for (int i = int(a); i < int(b); i++)
#define ffn(i, n) ff(i, 0, n)

static bool comp(vector<int> &v1, vector<int> &v2)
{
    return (v1[1] < v2[1]);
}

vector<vector<int>> aloc_ary(vector<vector<int>> a, int l, int m, int n)
{
    int i, k, o, b;
    vector<vector<int>> c(n, vector<int>(n, 0));

    for (k = 0, i = l; k < n; k++, i++)
        for (o = 0, b = m; o < n; o++, b++)
            c[k][o] = a[i][b];
    return c;
}

vector<vector<int>> adn_ary(vector<vector<int>> a, vector<vector<int>> b, int n)
{
    vector<vector<int>> c(n, vector<int>(n, 0));
    int i, j;
    ffn(i, n)
        ffn(j, n)
            c[i][j] = a[i][j] + b[i][j];
    return c;
}

vector<vector<int>> sbn_ary(vector<vector<int>> a, vector<vector<int>> b, int n)
{
    vector<vector<int>> c(n, vector<int>(n, 0));
    int i, j;
    ffn(i, n)
        ffn(j, n)
            c[i][j] = a[i][j] - b[i][j];
    return c;
}

void crt(vector<int> g[], int n, int st)
{
    queue<int> q;
    bool v[n + 1];
    memset(v, 0, sizeof(v));
    q.push(st);
    v[st] = 1;
    
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        ffn(j, g[a].size())
        {
            if (!v[g[a][j]])
            {
                q.push(g[a][j]);
                v[g[a][j]] = 1;
            }
        }
    }
}

void cbn_ary(vector<vector<int>> &c, vector<vector<int>> c11, int i, int j, int n)
{
    int a, b, x, y;
    for (a = 0, x = i; a < n; a++, x++)
        for (b = 0, y = j; b < n; b++, y++)
            c[x][y] = c11[a][b];
}

vector<vector<int>> mul_ary(vector<vector<int>> ary1, vector<vector<int>> ary2, int n)
{
    if (n == 1)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        res[0][0] = ary1[0][0] * ary2[0][0];
        return res;
    }

    vector<vector<int>> ary1_11 = aloc_ary(ary1, 0, 0, n / 2);
    vector<vector<int>> ary1_12 = aloc_ary(ary1, 0, n / 2, n / 2);
    vector<vector<int>> ary1_21 = aloc_ary(ary1, n / 2, 0, n / 2);
    vector<vector<int>> ary1_22 = aloc_ary(ary1, n / 2, n / 2, n / 2);
    vector<vector<int>> ary2_11 = aloc_ary(ary2, 0, 0, n / 2);
    vector<vector<int>> ary2_12 = aloc_ary(ary2, 0, n / 2, n / 2);
    vector<vector<int>> ary2_21 = aloc_ary(ary2, n / 2, 0, n / 2);
    vector<vector<int>> ary2_22 = aloc_ary(ary2, n / 2, n / 2, n / 2);

    vector<vector<int>> ary_tmp1 = mul_ary(adn_ary(ary1_11, ary1_22, n / 2), adn_ary(ary2_11, ary2_22, n / 2), n / 2);
    vector<vector<int>> ary_tmp2 = mul_ary(adn_ary(ary1_21, ary1_22, n / 2), ary2_11, n / 2);
    vector<vector<int>> ary_tmp3 = mul_ary(ary1_11, sbn_ary(ary2_12, ary2_22, n / 2), n / 2);
    vector<vector<int>> ary_tmp4 = mul_ary(ary1_22, sbn_ary(ary2_21, ary2_11, n / 2), n / 2);
    vector<vector<int>> ary_tmp5 = mul_ary(adn_ary(ary1_11, ary1_12, n / 2), ary2_22, n / 2);
    vector<vector<int>> ary_tmp6 = mul_ary(sbn_ary(ary1_21, ary1_11, n / 2), adn_ary(ary2_11, ary2_12, n / 2), n / 2);
    vector<vector<int>> ary_tmp7 = mul_ary(sbn_ary(ary1_12, ary1_22, n / 2), adn_ary(ary2_21, ary2_22, n / 2), n / 2);
    vector<vector<int>> res11 = adn_ary(sbn_ary(adn_ary(ary_tmp1, ary_tmp4, n / 2), ary_tmp5, n / 2), ary_tmp7, n / 2);
    vector<vector<int>> res12 = adn_ary(ary_tmp3, ary_tmp5, n / 2);
    vector<vector<int>> res21 = adn_ary(ary_tmp2, ary_tmp4, n / 2);
    vector<vector<int>> res22 = adn_ary(sbn_ary(adn_ary(ary_tmp1, ary_tmp3, n / 2), ary_tmp2, n / 2), ary_tmp6, n / 2);

    vector<vector<int>> res(n, vector<int>(n, 0));
    cbn_ary(res, res11, 0, 0, n / 2);
    cbn_ary(res, res12, 0, n / 2, n / 2);
    cbn_ary(res, res21, n / 2, 0, n / 2);
    cbn_ary(res, res22, n / 2, n / 2, n / 2);
    return res;
}

int main()
{
    int n, i, j, x;
    cin >> n;

    if (log2(n) != floor(log2(n)))
        x = pow(2, ceil(log2(n)));
    else
        x = n;

    vector<vector<int>> ary1(n, vector<int>(n,0));
    vector<vector<int>> ary2(n, vector<int>(n,0));
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", &ary1[i][j]);

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", &ary2[i][j]);

    vector<vector<int>> mul1(x + 1, vector<int>(x + 1, 0));
    vector<vector<int>> mul2(x + 1, vector<int>(x + 1, 0));

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            mul1[i][j] = ary1[i][j];
            mul2[i][j] = ary2[i][j];
        }
    }

    vector<vector<int>> res_arr(n, vector<int>(n, 0));
    res_arr = mul_ary(mul1, mul2, x);
    ffn(i, n)
    {
        ffn(j, n)
            cout << res_arr[i][j] << " ";
        cout << "\n";
    }
    return 0;
}