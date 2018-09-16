#include <iostream>
#include <cassert>
#include "../../../../src/tree/multiway_tree/union_find/union_find_dynamic.cpp"

int main()
{
    UnionFind<int> unionFind;

    unionFind.merge(3, 4);
    unionFind.merge(3, 8);
    unionFind.merge(0, 8);
    unionFind.merge(1, 3);
    unionFind.merge(7, 9);
    unionFind.merge(5, 9);

    // Now the components are:
    // 0 1 3 4 8
    // 5 7 9
    assert(unionFind.connected(0, 1));
    assert(unionFind.connected(0, 3));
    assert(unionFind.connected(0, 4));
    assert(unionFind.connected(0, 8));
    assert(unionFind.connected(1, 3));
    assert(unionFind.connected(1, 4));
    assert(unionFind.connected(1, 8));
    assert(unionFind.connected(3, 4));
    assert(unionFind.connected(3, 8));
    assert(unionFind.connected(4, 8));
    assert(unionFind.connected(5, 7));
    assert(unionFind.connected(5, 9));
    assert(unionFind.connected(7, 9));

    assert(!unionFind.connected(0, 5));
    assert(!unionFind.connected(0, 7));
    assert(!unionFind.connected(0, 9));
    assert(!unionFind.connected(1, 5));
    assert(!unionFind.connected(1, 7));
    assert(!unionFind.connected(1, 9));
    assert(!unionFind.connected(3, 5));
    assert(!unionFind.connected(3, 7));
    assert(!unionFind.connected(3, 9));
    assert(!unionFind.connected(4, 5));
    assert(!unionFind.connected(4, 7));
    assert(!unionFind.connected(4, 9));
    assert(!unionFind.connected(8, 5));
    assert(!unionFind.connected(8, 7));
    assert(!unionFind.connected(8, 9));

    return 0;
}
