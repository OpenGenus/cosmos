// Implemented by jhbecares based on Dijkstra's algorithm in "Competitive Programming 3"
// Example extracted from problem 10986 - Sending email from UVa Online Judge
/*
 * Try with the following data:
 * Sample Input
 * 3
 * 2 1 0 1
 * 0 1 100
 * 3 3 2 0
 * 0 1 100
 * 0 2 200
 * 1 2 50
 * 2 0 0 1
 *
 * Sample Output
 * 100
 * 150
 * unreachable
 */
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

using namespace std;

int n, m, S, T, w;

vector<vii> AdjList;
vi dist;
priority_queue<ii, vector<ii>, greater<ii>> pq;

void dijkstra(int s)
{

    dist.assign(n, 1e9);
    dist[s] = 0;

    pq.push(ii(0, s));

    while (!pq.empty())
    {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u])
            continue;
        for (int j = 0; j < (int)AdjList[u].size(); j++)
        {
            ii v = AdjList[u][j];
            if (dist[u] + v.second < dist[v.first])
            {
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }

    if (dist[T] == 1e9)
        cout << "unreachable" << endl;
    else
        cout << dist[T] << endl;
}

int main()
{
    int numCases;
    cin >> numCases;
    while (numCases--)
    {
        scanf("%d %d %d %d", &n, &m, &S, &T);

        AdjList.assign(n, vii());

        int n1, n2;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &n1, &n2, &w);
            AdjList[n1].push_back(ii(n2, w));
            AdjList[n2].push_back(ii(n1, w));
        }
        dijkstra(S);
    }

    return 0;
}
