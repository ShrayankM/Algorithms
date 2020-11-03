public class FlowEdge {

    private final int v;
    private final int w;
    private final double capacity;
    private double flow;

    FlowEdge(int v, int w, double capacity) {
        this.v = v;
        this.w = w;
        this.capacity = capacity;
        this.flow = 0.0;
    }

    public int from() {
        return v;
    }

    public int to() {
        return w;
    }

    public double capacity() {
        return capacity;
    }

    public double flow() {
        return flow;
    }

    public int other(int vertex) {
        if (vertex == v) return w;
        else             return v;
    }

    public double residualCapacity(int vertex) {
        if (vertex == v) return flow;
        else             return capacity - flow;
    }

    public void addResidualCapacityTo(int vertex, double delta) {
        if (vertex == v) flow = flow - delta;
        else             flow = flow + delta;
    }

    public String toString() {
        return String.format("%d->%d %.2f %.2f", v, w, capacity, flow);
    }
}
