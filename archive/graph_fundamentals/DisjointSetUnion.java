public class DisjointSetUnion {
    public static void main(String[] args) {
        DSU dsu = new DSU(6);

        dsu.union(0, 1);
        dsu.union(1, 2);
        dsu.union(3, 4);

        System.out.println(dsu.connected(0, 2)); // true
        System.out.println(dsu.connected(0, 3)); // false
        System.out.println(dsu.connected(3, 4)); // true
    }
}
