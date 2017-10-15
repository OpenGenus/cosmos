class UnionFind {
    int[] parent;
    int[] rank;
    UnionFind(int size) {
        parent = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    public int find(int v) {
        if (parent[v] == v) {
            return v;
        }
        parent[v] = find(parent[v]);
        return parent[v];
    }
    public boolean isConnected(int a, int b) {
        return find(a) == find(b);
    }
    public void connect(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
            parent[b] = a;
        }
    }
    public static void main(String[] args) {
        UnionFind unionFind = new UnionFind(10);

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

        for (int i = 0; i < 10; i++) {
            for (int j = i + 1; j < 10; j++) {
                if (unionFind.isConnected(i, j)) {
                    System.out.printf("%d and %d are in the same component\n", i, j);
                }
            }
        }
    }
};
