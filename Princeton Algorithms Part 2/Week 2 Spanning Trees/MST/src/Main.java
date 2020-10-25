import edu.princeton.cs.algs4.In;

public class Main {

    public static void main(String[] args) {
        String filename = args[0];
        In inOne = new In(filename);
        In inTwo = new In(filename);

        System.out.println("------------------------------ KRUSKAL'S OUTPUT ------------------------------");
        KruskalAlgorithm ka = new KruskalAlgorithm(inOne);

        for (Edge e : ka.MST()) {
            System.out.println(e);
        }
        System.out.println(ka.minCost());
        System.out.println("------------------------------ PRIMS OUTPUT ------------------------------");

        PrimsLazy pa = new PrimsLazy(inTwo);

        for (Edge e : pa.MST()) {
            System.out.println(e);
        }
        System.out.println(pa.minCost());
    }
}
