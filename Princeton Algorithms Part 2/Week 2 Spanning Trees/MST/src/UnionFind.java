public class UnionFind {

    private int [] parent;
    private int [] treeSize;

    UnionFind(int vertices) {
        parent = new int[vertices + 1];
        treeSize = new int[vertices + 1];
        for (int i = 0; i < vertices; i++) parent[i] = i;
        for (int i = 0; i < vertices; i++) treeSize[i] = 1;
    }

    public int findParent(int a) {
        while (a != parent[a]) a = parent[a];
        return a;
    }

    public void unite(int a, int b) {
        a = findParent(a);
        b = findParent(b);

        if (a == b) return;

        if (treeSize[a] < treeSize[b]) {
            parent[a] = b;
        }
        else {
            parent[b] = a;
            if (treeSize[a] == treeSize[b]) treeSize[a]++;
        }
    }

    public boolean sameSet(int a, int b) {
        return findParent(a) == findParent(b);
    }
}
