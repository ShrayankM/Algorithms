import edu.princeton.cs.algs4.Graph;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.SET;

public class WeightedGraph {

//    private Graph G;
    private Bag<Edge> edges;
    private SET<Integer> vertices;
    private int noVertices, noEdges;

    WeightedGraph(In in) {
        edges = new Bag<Edge>();
        vertices = new SET<Integer>();

        noVertices = Integer.parseInt(in.readString());
        noEdges = Integer.parseInt(in.readString());

//        G = new Graph(noVertices);

        while (!in.isEmpty()) {
            int v, w, weight;
            v = Integer.parseInt(in.readString());
            w = Integer.parseInt(in.readString());
            weight = Integer.parseInt(in.readString());

            addEdge(v, w, weight);
        }
    }

    public void addEdge(int v, int w, int weight) {
        vertices.add(v);
        vertices.add(w);

//        G.addEdge(v, w);
        Edge edge = new Edge(v, w, weight);
        edges.add(edge);
    }

    public int V() {
        return vertices.size();
    }

    public int E() {
        return edges.count();
    }

//    public Iterable<Integer> adj(int v) {
//        return G.adj(v);
//    }

    public Iterable<Edge> edges() {
        return edges;
    }
}
