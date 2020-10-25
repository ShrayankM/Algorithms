public class Edge implements Comparable<Edge> {

    private int v;
    private int w;
    private double weight;

    Edge(int v, int w, double weight) {
        this.v = v;
        this.w = w;
        this.weight = weight;
    }

    public int getV() {
        return v;
    }

    public int getW() {
        return w;
    }

    public double getWeight() {
        return weight;
    }

    @Override
    public String toString() {
        return "(" + v + ", " + w + ") Weight = " + weight;
    }

    @Override
    public int compareTo(Edge that) {
        return Double.compare(this.weight, that.weight);
    }
}
