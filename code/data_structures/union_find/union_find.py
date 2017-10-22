#!/usr/bin/env python


class UnionFind:

    def __init__(self):
        self.parent = {}
        self.rank = {}

    def root(self, a):
        current_item = a
        while self.parent[current_item] != current_item:
            current_item = self.parent[current_item]
        return current_item

    def connected(self, a, b):
        return self.root(a) == self.root(b)

    def find(self, a):
        return self.root(a)

    def union(self, a, b):
        if a not in self.parent:
            self.parent[a] = a
            self.rank[a] = 0
        if b not in self.parent:
            self.parent[b] = b
            self.rank[b] = 0
        a_root = self.root(a)
        b_root = self.root(b)
        if self.rank[a_root] > self.rank[b_root]:
            self.parent[b_root] = a_root
            self.rank[a_root] += 1
        else:
            self.parent[a_root] = b_root
            self.rank[b_root] += 1


def main():
    union_find = UnionFind()
    union_find.union(1, 3)
    union_find.union(1, 4)
    union_find.union(2, 5)
    union_find.union(5, 6)
    union_find.union(7, 8)
    union_find.union(7, 9)
    union_find.union(3, 9)
    for i in range(1, 9):
        for j in range(i + 1, 10):
            state = "connected" if union_find.connected(i, j) else "disconnected"
            print("{} and {} are {}".format(i, j, state))


if __name__ == "__main__":
    main()
