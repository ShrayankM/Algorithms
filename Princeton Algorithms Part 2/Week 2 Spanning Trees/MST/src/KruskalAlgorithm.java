import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Queue;

public class KruskalAlgorithm {

    private Queue<Edge> mst;
    private EdgeWeightedGraph G;
    private UnionFind UF;
//    private MinPQ<Edge> pq;
    private MinPQ<Edge> pq;
    private double cost = 0.0;

    KruskalAlgorithm(In in) {

        mst = new Queue<Edge>();
        G = new EdgeWeightedGraph(in);
        UF = new UnionFind(G.V());
        pq = new MinPQ<Edge>();

        for (Edge e : G.edges()) pq.insert(e);

        while (!pq.isEmpty()) {
            Edge e = pq.delMin();
            int v = e.getV(), w = e.getW();
            if (!UF.sameSet(v, w)) {
                mst.enqueue(e);
                UF.unite(v, w);
                cost += e.getWeight();
            }
        }
    }

    public double minCost() {
        return cost;
    }

    public Iterable<Edge> MST() {
        return mst;
    }
}
