#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXN = 8000;
const int INF = (int)1e9;

int n, m, *deg, *par, tl = -1;
bool *used;
vector <vector <int>> G;

inline void count_degs()
{
    for (int i = 0; i < n; i++)
        deg[i] = G[i].size();
}

bool DFS(int v, int p = -1)
{
    tl = v;
    used[v] = 1;
    par[v] = p;
    int gmin = INF;
    int cnt = 1;
    for (unsigned int i = 0; i < G[v].size(); i++)
        deg[G[v][i]]--;
    for (unsigned int i = 0; i < G[v].size(); i++)
        if (!used[G[v][i]])
        {
            if (deg[G[v][i]] < gmin)
            {
                gmin = deg[G[v][i]];
                cnt = 1;
            }
            else if (deg[G[v][i]] == gmin)
                cnt++;
        }
    int num = rand() % cnt;
    cnt = 0;
    for (unsigned int i = 0; i < G[v].size(); i++)
        if (!used[G[v][i]])
            if (deg[G[v][i]] == gmin)
                if (cnt++ == num)
                    return DFS(G[v][i], v);

    return false;
}

int main()
{
    cin >> n >> m;
    deg = new int[n];
    par = new int[n];
    used = new bool[n];
    G.resize(n);
    for (int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        G[--t1].push_back(--t2);
        G[t2].push_back(t1);
    }
    for (int iter = 0;; iter++)
    {
        tl = -1;
        count_degs();
        memset(used, 0, n * sizeof(used[0]));
        memset(par, 0, n * sizeof(par[0]));
        int vert = rand() % n;
        DFS(vert);
        bool flag = true;
        for (int j = 0; j < n; j++)
            if (!used[j])
                flag = false;

        if (flag)
        {
            for (int j = tl; j != -1; j = par[j])
                cout << j + 1;
            cout << "\n";
            return 0;
        }
    }
}
