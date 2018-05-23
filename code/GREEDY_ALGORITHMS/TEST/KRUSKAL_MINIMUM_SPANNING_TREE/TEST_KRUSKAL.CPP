#include "../../src/kruskal_minimum_spanning_tree/kruskal.cpp"
#include "../../../data_structures/src/tree/multiway_tree/union_find/union_find_dynamic.cpp"
#include <iostream>

using namespace std;

pair<int, int> edgeFunc(pair<pair<int, int>, int> edge)
{
    return edge.first;
}

class HeapCompare
{
public:
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
    {
        return a.second > b.second;
    }
};

int main()
{
    using namespace std;
    vector<int> vec{1, 2, 3, 4, 5, 6, 7};

    /*
     *    1---(12)----2
     *   /           / \
     *  /           /   \
     * (35)       (25)  (24)
     * /           /      \
     * /           /        \
     * 6           7          3
     \         /\         /
     \       /  \       /
     \ (15) (18)  (22)  (32)
     \  /        \   /
     \/          \ /
     \    5---(10)----4
     */
    vector<pair<pair<int, int>, int>> edge_weight{{{1, 2}, 12},
                                                  {{2, 3}, 24},
                                                  {{3, 4}, 32},
                                                  {{4, 5}, 10},
                                                  {{5, 6}, 15},
                                                  {{6, 1}, 35},
                                                  {{2, 7}, 25},
                                                  {{4, 7}, 22},
                                                  {{5, 7}, 18}};

    make_heap(edge_weight.begin(), edge_weight.end(), HeapCompare());

    auto res = kruskal(vec.size() - 1,
                       edge_weight,
                       HeapCompare(),
                       edgeFunc, UnionFind<int>());

    // print
    auto it = res.begin();
    while (it != res.end())
    {
        cout << it->first.first << "\t" << it->first.second << endl;
        ++it;
    }
    /*
     *    1---(12)----2
     *               / \
     *              /   \
     *           (25)  (24)
     *            /      \
     *           /        \
     * 6           7          3
     \         /
     \       /
     \ (15) (18)
     \  /
     \/
     \    5---(10)----4
     */

    return 0;
}
