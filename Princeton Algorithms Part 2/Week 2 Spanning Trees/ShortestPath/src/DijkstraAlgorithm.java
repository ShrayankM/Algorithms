import edu.princeton.cs.algs4.In;

import java.util.Arrays;

public class DijkstraAlgorithm {

    private EdgeWeightedDiGraph G;
    private MinPQ<Vertex> pq;
    private double [] distTo;
    private boolean [] visited;
    private int visitedCnt = 0;
    private int [] edgeTo;
    private double INF = Double.MAX_VALUE;
    private int source;

    DijkstraAlgorithm(In in, int source) {

        G = new EdgeWeightedDiGraph(in);
        visited = new boolean[G.V()];
        edgeTo = new int[G.V()];
        pq = new MinPQ<Vertex>();
        distTo = new double[G.V()];
        this.source = source;

        Arrays.fill(distTo, INF);
        Arrays.fill(visited, false);
        Arrays.fill(edgeTo, -1);
        distTo[source] = 0.0;

        pq.insert(new Vertex(0, 0.0));
        while (!pq.isEmpty() && visitedCnt < G.V()) {
            Vertex V = pq.delMin();

            int vertex = V.vertex();
            if (visited[vertex]) continue;
            visited[vertex] = true;
            visitedCnt++;

            for (Edge e : G.adj(vertex)) {
                int v = e.getV(), w = e.getW(v);
                Vertex n;
                if (v == vertex) n = new Vertex(w, e.getWeight());
                else             n = new Vertex(v, e.getWeight());

                if (visited[n.vertex()]) continue;
                if (distTo[n.vertex()] > e.getWeight() + distTo[vertex]) {
                    distTo[n.vertex()] = e.getWeight() + distTo[vertex];
                    edgeTo[n.vertex()] = vertex;
                    n.updateWeight(distTo[n.vertex()]);
                    pq.insert(n);
                }
            }
        }
    }
    public void viewDistance() {
        for (int i = 0; i < distTo.length; i++) {
            System.out.println("Distance from Source " + this.source + " to vertex " + i + " = " + distTo[i]);
        }
    }
}
