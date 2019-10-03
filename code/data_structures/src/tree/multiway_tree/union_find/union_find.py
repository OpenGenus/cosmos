#!/usr/bin/env python


class UnionFind:
    def __init__(self):
        self.parent = {}
        self.rank = {}

    def root(self, a):
        current_item = a
        path = []
        while self.parent[current_item] != current_item:
            path.append(current_item)
            current_item = self.parent[current_item]
        for node in path:
            self.parent[node] = current_item
        return current_item

    def connected(self, a, b):
        return self.root(a) == self.root(b)

    def find(self, a):
        return self.root(a)

    def create(self, a):
        if a not in self.parent:
            self.parent[a] = a
            self.rank[a] = 1

    def union(self, a, b):
        self.create(a)
        self.create(b)
        a_root = self.root(a)
        b_root = self.root(b)
        if self.rank[a_root] > self.rank[b_root]:
            self.parent[b_root] = a_root
            self.rank[a_root] += self.rank[b_root]
        else:
            self.parent[a_root] = b_root
            self.rank[b_root] += self.rank[a_root]

    def count(self, a):
        if a not in self.parent:
            return 0
        return self.rank[self.root(a)]


def main():
    union_find = UnionFind()
    union_find.union(1, 3)
    union_find.union(1, 4)
    union_find.union(2, 5)
    union_find.union(5, 6)
    union_find.union(7, 8)
    union_find.union(7, 9)
    union_find.union(3, 9)
    for i in range(1, 10):
        print(
            "{} is in group {} with {} elements".format(
                i, union_find.find(i), union_find.count(i)
            )
        )


if __name__ == "__main__":
    main()
