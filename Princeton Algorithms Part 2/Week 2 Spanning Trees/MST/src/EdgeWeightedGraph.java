import edu.princeton.cs.algs4.In;

import java.util.Iterator;

public class EdgeWeightedGraph {

    private Bag<Edge> [] adj;
    private Bag<Edge> edges;
    private int vertices, edgesCount;

    EdgeWeightedGraph(In in) {
        edges = new Bag<Edge>();
        this.vertices = Integer.parseInt(in.readLine());
        this.edgesCount    = Integer.parseInt(in.readLine());
        adj = (Bag<Edge>[]) new Bag[this.vertices];

        for (int i = 0; i < vertices; i++) adj[i] = new Bag<Edge>();

        while (!in.isEmpty()) {
            int v, w;
            double weight;

            v = Integer.parseInt(in.readString());
            w = Integer.parseInt(in.readString());
            weight = Double.parseDouble(in.readString());

            Edge e = new Edge(v, w, weight);
            edges.add(e);
            addEdge(e);
        }
    }

    public void addEdge(Edge e) {
        int v = e.getV(), w = e.getW();
        adj[v].add(e);
        adj[w].add(e);
    }

    public int V() {
        return vertices;
    }

    public int E() {
        return edgesCount;
    }

    public Iterable<Edge> edges() {
        return edges;
    }

    public Iterable<Edge> adj(int v) {
        return adj[v];
    }
}
