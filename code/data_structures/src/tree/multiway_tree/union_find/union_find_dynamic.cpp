/* Part of Cosmos by OpenGenus Foundation */

// Union-find stores a graph, and allows two operations in amortized constant time:
// * Add a new edge between two vertices.
// * Check if two vertices belong to same component.

#include <unordered_map>
#include <unordered_set>
#include <algorithm>

// dynamic union find (elementary implementation)
template<typename _ValueType, typename _Hash = std::hash<_ValueType>>
class UnionFind
{
public:
    using value_type = _ValueType;

    UnionFind()
    {
    }

// Connect vertices `a` and `b`.
    void merge(value_type a, value_type b)
    {
        // 1. to guarantee that the set has both `a` and `b`
        auto na = nodes.find(a);
        auto nb = nodes.find(b);

        if (na == nodes.end())
        {
            nodes.insert(a);
            na = nodes.find(a);
            parents.insert({na, na});
        }

        if (nb == nodes.end())
        {
            nodes.insert(b);
            nb = nodes.find(b);
            parents.insert({nb, nb});
        }

        // 2. update the map
        auto pa = parents.find(na);

        while (pa != parents.end() && pa->first != pa->second)
            pa = parents.find(pa->second);

        if (pa != parents.end())
            na = pa->second;

        parents[na] = nb;
    }

    value_type find(value_type node)
    {
        auto root = nodes.find(node);

        // new node
        if (root == nodes.end())
        {
            // auto it = nodes.insert(node);
            nodes.insert(node);
            auto it = nodes.find(node);
            parents.insert({it, it});

            return node;
        }
        // existed
        else
        {
            auto pr = parents.find(root);
            while (pr != parents.end() && pr->first != pr->second)
                pr = parents.find(pr->second);

            return *(parents[root] = pr->second);
        }
    }

    bool connected(value_type a, value_type b)
    {
        return find(a) == find(b);
    }

private:
    using Set = std::unordered_set<value_type, _Hash>;
    using SetIt = typename Set::iterator;

    struct SetItHash
    {
        size_t operator()(const SetIt& it) const
        {
            return std::hash<const int*>{} (&*it);
        }
    };

    Set nodes;
    std::unordered_map<SetIt, SetIt, SetItHash> parents;
};
