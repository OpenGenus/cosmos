/*this includes code for cheking the cycle is undirected graph using unionfind disjoint data structure
 *
 * the implementation is very fast
 * as it implements unionfind disjoint structure using path-compression and rank heuristics
 */

#include <vector>
#include <cstddef>

int p[1000000];  //stores parent
int rnk[1000000];

int findset(int u)  //find set representative of u
{
    if (u == p[u])
        return u;
    return p[u] = findset(p[u]);
}

void unionset(int i, int j)  //merge sets with elements i and j
{
    int a = findset(i);
    int b = findset(j);

    if (a != b)
    {
        if (rnk[a] > rnk[b])
            p[b] = a;
        else
            p[a] = b;
        if (rnk[a] == rnk[b])
            ++rnk[b];
    }
}
//note that edgelist can be formed using graph input itself
bool detectcycle(std::vector<std::pair<int, int>> edgelist) // graph given in edge list representation
{
    for (std::size_t i = 0; i < edgelist.size(); ++i)
    {
        std::pair<int, int> u = edgelist[i];
        int a = u.first;
        int b = u.second;
        if (findset(a) == findset(b))
            return true;
        else
            unionset(a, b);
    }
    return false;
}
