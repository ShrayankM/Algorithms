import edu.princeton.cs.algs4.In;

public class DiGraph {

    private Bag<Integer> [] adj;
    private int vertices = 0, edges = 0;

    DiGraph(int V) {
        adj = (Bag<Integer> []) new Bag[V];
        for (int i = 0; i < adj.length; i++) adj[i] = new Bag<Integer>();
    }

    DiGraph(In in) {
        this.vertices = Integer.parseInt(in.readLine());
        this.edges = Integer.parseInt(in.readLine());

        adj = (Bag<Integer> []) new Bag[this.vertices];
        for (int i = 0; i < adj.length; i++) adj[i] = new Bag<Integer>();

        while (!in.isEmpty()) {
            String [] str = in.readLine().split(" ");
            int v = Integer.parseInt(str[0]);
            int w = Integer.parseInt(str[1]);

            addEdge(v, w);
        }
    }

    void addEdge(int v, int w) {
        adj[v].insert(w);
    }

    Iterable<Integer> adj(int v) {
        return adj[v];
    }

    int V() {
        return vertices;
    }

    int E() {
        return edges;
    }

    DiGraph reverse() {
        DiGraph rv = new DiGraph(this.vertices);
        for (int i = 0; i < adj.length; i++) {
            int v = i;
            for (int w : adj[v]) {
                rv.adj[w].insert(i);
            }
        }
        rv.vertices = this.vertices;
        rv.edges = this.edges;
        return rv;
    }

    @Override
    public String toString() {
        return super.toString();
    }
}
