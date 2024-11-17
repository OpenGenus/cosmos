#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// Part of Cosmos by OpenGenus Foundation

const int maxN = 1E5;
const long long INF = 1E18;
vector<pair<int, long long> > graph[maxN];
vector<pair<long long,int> > heap;
long long dist[maxN];
bool visited[maxN];

/*
Example

6 6 0
0 1 1
0 3 5
0 2 10
1 3 1
2 3 -11
3 4 1

*/

int main()
{
    //N: number of verteces, M: number of edges, S: Source
    //vertex indices goes from 0 to N-1
    int N, M, S;
    cin >> N >> M >> S;
    for(int i=0; i<M; i++){
        //u -> v edge with weight w
        int u, v;
        long long w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    //dist[i] is INF if i is not reached yet
    for(int i=0; i<N; i++) dist[i] = INF;

    //making heap, using -1*dist, because heap gives back the maximal element, not the minimal
    dist[S] = 0;
    heap.push_back({-dist[S],S});
    make_heap(heap.begin(),heap.end());
    while (!heap.empty())
    {
        //finding closest vertex
        pair<long long, int> p = heap.front();
        pop_heap(heap.begin(),heap.end());
        heap.pop_back();

        int u = p.second;
        if(!visited[u]){
            visited[u] = true;
            for (pair<int,long long> v : graph[u]){
                if (dist[v.first] > (dist[u] + v.second)){
                    dist[v.first] = dist[u] + v.second;
                    //we have to visit sometime v again if we have negativ weights (but not works for negative cycle)
                    visited[v.first] = false;
                    heap.push_back({-dist[v.first], v.first});
                    push_heap(heap.begin(),heap.end());
                }
            }
        }

    }
    for(int i=0; i<N; i++){
        cout << i << ": ";
        if(i==S){
            cout << "Source, distance is 0\n";
        } else {
            if(dist[i]==INF){
                cout << "Not reached\n";
            } else {
                cout << dist[i] << '\n';
            }
        }
    }
    return 0;
}
