public class DSU {
    private int[] parent;
    private int[] size;  // for 'union by size'

    DSU(int n) {
        parent = new int[n];
        size = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);  // path compression (x directly attaches to root, so depth is less, hence future find() operations are quicker)
    }

    void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) return;

        // union by size: attach smaller tree to bigger tree, so depth is  incremented for fewer children (nodes of smaller tree)
        if (size[rootA] >= size[rootB]) {
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        } else {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
    }

    boolean connected(int a, int b) {
        return find(a) == find(b);
    }
}
