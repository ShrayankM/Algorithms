import edu.princeton.cs.algs4.In;
import java.util.Comparator;

public class Main {

    public static void main(String[] args) {
        String filename = args[0];
        In inOne = new In(filename);
        In inTwo = new In(filename);
        In inThree = new In(filename);

        System.out.println("------------------------------ KRUSKAL'S OUTPUT ------------------------------");
        KruskalAlgorithm ka = new KruskalAlgorithm(inOne);

        for (Edge e : ka.MST()) {
            System.out.println(e);
        }
        System.out.println(ka.minCost());
        System.out.println("------------------------------ PRIMS LAZY OUTPUT ------------------------------");

        PrimsLazy pa = new PrimsLazy(inTwo);

        for (Edge e : pa.MST()) {
            System.out.println(e);
        }
        System.out.println(pa.minCost());

        System.out.println("------------------------------ PRIMS EAGER OUTPUT ------------------------------");
        PrimsEager pe = new PrimsEager(inThree);

        pe.viewEdgeTo();
        System.out.println(pe.minCost());
    }
}
