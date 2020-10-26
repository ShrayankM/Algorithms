import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Queue;

import java.util.Arrays;
import java.util.Iterator;

public class PrimsEager {

    private EdgeWeightedGraph G;
    private boolean [] visited;
    private Queue<Edge> mst;
    private MinPQ<Vertex> pq;
    private double [] distTo;
    private int [] edgeTo;
    private double INF = Double.MAX_VALUE;
    private double minCost = 0.0;

    PrimsEager(In in) {
        G = new EdgeWeightedGraph(in);
        visited = new boolean[G.V()];
        mst = new Queue<Edge>();
        distTo = new double[G.V()];
        edgeTo = new int[G.V()];
        pq = new MinPQ<Vertex>();

        Arrays.fill(visited, false);
        Arrays.fill(distTo, INF);

        distTo[0] = 0.0;
        pq.insert(new Vertex(0, 0.0));

        while (!pq.isEmpty()) {
            System.out.println(pq.size());
            Vertex V = pq.delMin();

            int vertex = V.vertex();
            if (visited[vertex]) continue;
            visited[vertex] = true;

            if (vertex != 0)
            minCost += V.getWeight();

            for (Edge e : G.adj(vertex)) {
                int v = e.getV(), w = e.getW(v);
                Vertex n;
                if (v == vertex) n = new Vertex(w, e.getWeight());
                else             n = new Vertex(v, e.getWeight());

                if (visited[n.vertex()]) continue;
                if (distTo[n.vertex()] > e.getWeight()) {
                    distTo[n.vertex()] = e.getWeight();
                    edgeTo[n.vertex()] = vertex;
                    pq.insert(n);
                }
            }
        }
    }

    public void viewEdgeTo() {
        for (int i = 0; i < edgeTo.length; i++) {
             System.out.println("(" + i + ", " + edgeTo[i] + ") Weight = " + distTo[i]);
        }
    }

    public double minCost() {
        return minCost;
    }
}
