#include <iostream>
#include <vector>

/* Part of Cosmos by OpenGenus Foundation */

// Union-find stores a graph, and allows two operations in amortized constant time:
// * Add a new edge between two vertices.
// * Check if two vertices belong to same component.
class UnionFind {
    std::vector<size_t> parent;
    std::vector<size_t> rank;

    size_t getParent(size_t node) {
        if (parent[node] == node) {
            return node;
        } else {
            return parent[node] = getParent(parent[node]);
        }
    }

public:
    // Make a graph with `size` vertices and no edges.
    UnionFind(size_t size) {
        parent.resize(size);
        rank.resize(size);
        for (size_t i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    // Connect vertices `a` and `b`.
    void connect(size_t a, size_t b) {
        a = getParent(a);
        b = getParent(b);
        if (a == b) {
            return;
        }
        if (rank[a] < rank[b]) {
            parent[a] = b;
        } else if (rank[a] > rank[b]) {
            parent[b] = a;
        } else {
            parent[a] = b;
            rank[b] += 1;
        }
    }

    // Check if vertices `a` and `b` are in the same component.
    bool areConnected(size_t a, size_t b) {
        return getParent(a) == getParent(b);
    }
};

int main() {
    UnionFind unionFind(10);

    unionFind.connect(3, 4);
    unionFind.connect(3, 8);
    unionFind.connect(0, 8);
    unionFind.connect(1, 3);
    unionFind.connect(7, 9);
    unionFind.connect(5, 9);

    // Now the components are:
    // 0 1 3 4 8
    // 5 7 9
    // 2
    // 6
    
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = i + 1; j < 10; j++) {
            if (unionFind.areConnected(i, j)) {
                std::cout << i << " and " << j << " are in the same component" << std::endl;
            }
        }
    }

    return 0;
}