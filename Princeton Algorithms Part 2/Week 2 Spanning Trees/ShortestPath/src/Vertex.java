public class Vertex implements Comparable<Vertex> {

    private int v;
    private double weight;

    Vertex(int v, double weight) {
        this.v = v;
        this.weight = weight;
    }

    public int vertex() {
        return this.v;
    }

    public double getWeight() {
        return this.weight;
    }

    public void updateWeight(double weight) {
        this.weight = weight;
    }

    @Override
    public int compareTo(Vertex that) {
        return Double.compare(this.weight, that.weight);
    }
}
