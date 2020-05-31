#include <iostream>
#include <queue>

using namespace std;

int bipartite(int g[][10], int s, int n)
{
    int *col = new int [n];

    for (int i = 0; i < n; i++)
        col[i] = -1;

    queue<int> q;

    col[s] = 1;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (g[u][u] == 1)
            return 0;

        for (int v = 0; v < n; v++)
        {
            if (g[u][v] && col[v] == -1)
            {
                col[v] = 1 - col[u];
                q.push(v);
            }
            else if (g[u][v] == 1 && col[u] == col[v])
                return 0;
        }
    }

    return 1;
}


int main()
{
    int g[10][10], n;

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    int x = bipartite(g, 0, n);

    cout << x << endl;
    return 0;
}
