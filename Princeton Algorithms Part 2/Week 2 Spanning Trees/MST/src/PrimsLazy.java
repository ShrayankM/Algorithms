import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Queue;

import java.util.Arrays;

public class PrimsLazy {

    private EdgeWeightedGraph G;
    private Queue<Edge> mst;
    private MinPQ<Edge> pq;
    private Edge minEdge;
    private boolean [] marked;
    private double minCost = 0.0;

    PrimsLazy(In in) {

        G = new EdgeWeightedGraph(in);
        mst = new Queue<Edge>();
        pq = new MinPQ<Edge>();
        marked = new boolean[G.V()];

        Arrays.fill(marked, false);

        minEdge = new Edge(-1, -1, Double.MAX_VALUE);

        for (Edge e : G.edges()) {
            if (e.compareTo(minEdge) < 0) minEdge = e;
        }

        mst.enqueue(minEdge);
        minCost += minEdge.getWeight();
//        pq.insert(minEdge);
        int v = minEdge.getV(), w = minEdge.getW();

        marked[v] = true;
        marked[w] = true;

        insertEdges(v);
        insertEdges(w);
//        for (Edge e : G.adj(v)) pq.insert(e);
//        for (Edge e : G.adj(w)) pq.insert(e);

        while (!pq.isEmpty()) {
            Edge e = pq.delMin();
            v = e.getV(); w = e.getW();
            if (marked[v] && marked[w]) continue;
            mst.enqueue(e);
            minCost += e.getWeight();

            if (!marked[v]) {
                insertEdges(v);
//                for (Edge edge : G.adj(v)) pq.insert(edge);
                marked[v] = true;
            }

            if (!marked[w]) {
                insertEdges(w);
//                for (Edge edge : G.adj(w)) pq.insert(edge);
                marked[w] = true;
            }
        }
    }

    private void insertEdges(int a) {
        for (Edge e : G.adj(a)) pq.insert(e);
    }

    public double minCost() {
        return minCost;
    }

    public Iterable<Edge> MST() {
        return mst;
    }
}
