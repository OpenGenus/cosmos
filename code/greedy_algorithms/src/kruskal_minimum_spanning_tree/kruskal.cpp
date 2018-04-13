#include <algorithm>
#include <vector>

namespace kruskal_impl {
using namespace std;

template<typename _ForwardIter, typename _ValueType>
pair<_ValueType, _ValueType> edgeFuncPolicy(_ForwardIter it);

template<typename _ValueType>
struct UnionFindPolicy
{
    void merge(_ValueType a, _ValueType b);

    bool connected(_ValueType a, _ValueType b);
};
} // kruskal_impl

template<typename _HeapedContainer,
         typename _HeapCompare,
         typename _EdgeFunc,
         typename _UnionFind>
std::vector<typename _HeapedContainer::value_type>
kruskal(const size_t minimum_edge_count,
        _HeapedContainer edges,
        _HeapCompare compare,
        _EdgeFunc ef,
        _UnionFind union_sets)
{
    using namespace std;
    using value_type = typename _HeapedContainer::value_type;

    auto min_spanning_tree = vector<value_type>{};

    while (min_spanning_tree.size() < minimum_edge_count && !edges.empty())
    {
        // the pick elem is on the back
        pop_heap(edges.begin(), edges.end(), compare);
        auto edge = ef(edges.back());

        // cycle detection
        if (!union_sets.connected(edge.first, edge.second))
        {
            union_sets.merge(edge.first, edge.second);
            min_spanning_tree.push_back(edges.back());
        }

        edges.pop_back();
    }

    return min_spanning_tree;
}
