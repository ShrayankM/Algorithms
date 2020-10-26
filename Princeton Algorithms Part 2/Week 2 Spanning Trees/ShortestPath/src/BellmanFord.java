import edu.princeton.cs.algs4.In;

import java.util.Arrays;

public class BellmanFord {

    private EdgeWeightedDiGraph G;
    private double [] distTo;
    private int source;
    private double INF = Double.MAX_VALUE;

    BellmanFord(In in, int source) {
        G = new EdgeWeightedDiGraph(in);
        distTo = new double[G.V()];

        Arrays.fill(distTo, INF);
        this.source = source;
        distTo[source] = 0.0;

        int swaps;
        for (int i = 0; i < G.V() - 1; i++) {
            swaps = 0;
            for (Edge e : G.edges()) {
                int v = e.getV(), w = e.getW(v);
                if (distTo[w] > distTo[v] + e.getWeight()) {
                    swaps++;
                    distTo[w] = distTo[v] + e.getWeight();
                }
            }
            if (swaps == 0) break;
        }
    }

    public void viewDistance() {
        for (int i = 0; i < distTo.length; i++) {
            System.out.println("Distance from Source " + this.source + " to vertex " + i + " = " + distTo[i]);
        }
    }
}
