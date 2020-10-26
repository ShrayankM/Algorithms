import edu.princeton.cs.algs4.In;

import java.util.Arrays;

public class AcyclicPath {

    private EdgeWeightedDiGraph G;
    private double [] distTo;
    private int [] edgeTo;
    private boolean [] visited;
    private double INF = Double.MAX_VALUE;
    private TopologicalOrder order;

    AcyclicPath(In in) {
        G = new EdgeWeightedDiGraph(in);
        order = new TopologicalOrder(G);

        distTo = new double[G.V()];
        Arrays.fill(distTo, INF);

        edgeTo = new int[G.V()];
        visited = new boolean[G.V()];

        Arrays.fill(visited, false);

        distTo[order.startVertex()] = 0.0;

        for (int vertex : order.tOrder()) {
            visited[vertex] = true;
            for (Edge e : G.adj(vertex)) {

                int v = e.getV(), w = e.getW(v);
                Vertex n;
                if (v == vertex) n = new Vertex(w, e.getWeight());
                else             n = new Vertex(v, e.getWeight());

                if (visited[n.vertex()]) continue;
                if (distTo[n.vertex()] > e.getWeight() + distTo[vertex]) {
                    distTo[n.vertex()] = e.getWeight() + distTo[vertex];
                    edgeTo[n.vertex()] = vertex;
                }
            }
        }
    }

    public void viewDistance() {
        for (int i = 0; i < distTo.length; i++) {
            System.out.println("Distance from Source " + order.startVertex()  + " to vertex " + i + " = " + distTo[i]);
        }
    }
}
