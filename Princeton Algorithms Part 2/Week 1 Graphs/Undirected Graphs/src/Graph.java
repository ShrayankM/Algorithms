import edu.princeton.cs.algs4.In;

public class Graph {

    private Bag<Integer> [] adj;
    private int vertices, edges;
    // create an empty graph with V vertices
    Graph(int V) {
        this.vertices = V;
        adj = (Bag<Integer>[]) new Bag[V];
        for (int i = 0; i < adj.length; i++) {
            adj[i] = new Bag<Integer>();
        }
    }

    // create a graph from input Stream
    Graph(In in) {
        this.vertices = Integer.parseInt(in.readLine());
        this.edges = Integer.parseInt(in.readLine());

        adj = (Bag<Integer>[]) new Bag[this.vertices];
        for (int i = 0; i < adj.length; i++) {
            adj[i] = new Bag<Integer>();
        }

//        System.out.println(this.V() + " " + this.E());
        while (!in.isEmpty()) {
            String [] str = in.readLine().split(" ");
            int v = Integer.parseInt(str[0]);
            int w = Integer.parseInt(str[1]);

            addEdge(v, w);
        }
    }

    // add an edge v - w
    public void addEdge(int v, int w) {
        this.edges++;
        adj[v].insert(w);
        adj[w].insert(v);
    }

    // vertices adjacent to v
    public Iterable<Integer> adj(int v) {
        return adj[v];
    }

    // number of vertices
    public int V() {
        return vertices;
    }

    // number of edges
    public int E() {
        return edges;
    }

    // String Representation
    @Override
    public String toString() {
        return super.toString();
    }
}
