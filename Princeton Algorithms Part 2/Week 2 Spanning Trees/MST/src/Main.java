import edu.princeton.cs.algs4.In;
import java.util.Comparator;

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
//        Integer [] arr = {12, 6, 64, 4, 17, 56};
//        MinPQ<Integer> pq = new MinPQ<>();
//
//        for (int i = 0; i < arr.length; i++) {
//            pq.insert(arr[i]);
//        }
//
//        System.out.println(pq.delMin());
//        System.out.println(pq.delMin());
//        System.out.println(pq.delMin());
//        System.out.println(pq.delMin());
//        System.out.println(pq.delMin());
//        System.out.println(pq.delMin());
//
//        System.out.println(pq.isEmpty());
//
//        for (int i = 0; i < arr.length; i++) {
//            pq.insert(arr[i]);
//        }
//
//        for (int value : pq) {
//            System.out.print(value + " ");
//        }
//        System.out.println();
    }
}
