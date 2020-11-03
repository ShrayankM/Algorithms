import edu.princeton.cs.algs4.Queue;

public class FordFulkerson {

    private FlowEdge [] edgeTo;
    private boolean [] marked;
    private double value;

    FordFulkerson(FlowNetwork G, int s, int t) {
        while (hasAugmentingPath(G, s, t)) {

            double bottle = Double.POSITIVE_INFINITY;
            for (int v = t; v != s; v = edgeTo[v].other(v))
                bottle = Math.min(bottle, edgeTo[v].residualCapacity(v));

            for (int v = t; v != s; v = edgeTo[v].other(v))
                edgeTo[v].addResidualCapacityTo(v, bottle);

            value += bottle;
        }
    }

    public double maxFlow() {
        return value;
    }

    public boolean hasAugmentingPath(FlowNetwork G, int s, int t) {
        edgeTo = new FlowEdge[G.V()];
        marked = new boolean[G.V()];

        Queue<Integer> q = new Queue<Integer>();
        q.enqueue(s);
        marked[s] = true;

        while (!q.isEmpty()) {
            int v = q.dequeue();
            for (FlowEdge e : G.adj(v)) {

                int w = e.other(v);
                if (e.residualCapacity(w) > 0 && !marked[w]) {
                    edgeTo[w] = e;
                    marked[w] = true;
                    q.enqueue(w);
                }
            }
        }
        return marked[t];
    }
}
