import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.In;

public class Main {

    public static void main(String[] args) {
        String filename = args[0];
        In in = new In(filename);

        DiGraph dg = new DiGraph(in);
        StronglyConnected scc = new StronglyConnected(dg);

        System.out.println(scc.totalComponents());
        scc.viewComponents();
    }
}
