#include <iostream>
#include <vector>


const int MOD = 1000000007;

int size, n;

std::vector< std::vector<long long>> multiple (std::vector< std::vector<long long>> a,
                                               std::vector< std::vector<long long>> b)
{
    std::vector< std::vector<long long>> res(size);

    for (int i = 0; i < size; i++)
        res[i].resize(size);

    for (int i = 0; i < size; i++)
        for (int l = 0; l < size; l++)
        {
            long long tmp = 0;

            for (int j = 0; j < size; j++)
                tmp = (tmp + a[i][j] * b[j][l]) % MOD;

            res[i][l] = tmp;
        }

    return res;
}

std::vector< std::vector<long long>> binPow(std::vector< std::vector<long long>> a, long long power)
{
    std::vector< std::vector<long long>> ans(size);

    for (int i = 0; i < size; i++)
    {
        ans[i].resize(size);
        ans[i][i] = 1;
    }

    std::vector< std::vector<long long>> cur = a;

    while (power)
    {
        if (power & 1)
            ans = multiple (ans, cur);
        cur = multiple (cur, cur);
        power /= 2;
    }

    return ans;
}

int main ()
{
    std::cin >> size >> n;

    int from, to;
    std::cin >> from >> to;

    std::vector< std::vector<long long>> graph(size);

    for (int i = 0; i < size; i++)
        graph[i].resize(size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            std::cin >> graph[i][j];

    std::cout << binPow(graph, n)[from][to];
}
