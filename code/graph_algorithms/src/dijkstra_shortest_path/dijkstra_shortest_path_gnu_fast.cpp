#include <climits>
#include <ext/pb_ds/priority_queue.hpp>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using namespace __gnu_pbds;
template <class X, class C = greater<X>>
using heap = __gnu_pbds::priority_queue<X, C>;
vector<heap<pair<int, int>>::point_iterator> pt;
vector<int> d;
vector<vector<pair<int, int>>> g;
void dijkstra(int s)
{
    fill(d.begin(), d.end(), INT_MAX);
    d[s] = 0;
    heap<pair<int, int>> q;
    pt[s] = q.push(make_pair(d[s], s));
    while (!q.empty())
    {
        auto v = q.top().second;
        q.pop();
        for (auto x : g[v])
            if (d[v] + x.second < d[x.first])
            {
                d[x.first] = d[v] + x.second;
                if (pt[x.first] != nullptr)
                    q.modify(pt[x.first], make_pair(d[x.first], x.first));
                else
                    q.push(make_pair(d[x.first], x.first));
            }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    d.resize(n);
    g.resize(n);
    pt.resize(n);

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        // vertices must be in range [0, n)
        x--;
        y--;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    int s;
    cin >> s;
    s--;
    dijkstra(s);
    // d[i] == INT_MAX then there is no way between s and i
    for (auto x : d)
        cout << x << ' ';
    return 0;
}
