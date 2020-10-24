import edu.princeton.cs.algs4.In;

import java.util.Iterator;

public class Main {

    public static void main(String[] args) {

        String filename = args[0];
        In in = new In(filename);
        Graph g = new Graph(in);

        FindEulerPath fep = new FindEulerPath(g);
    }
}
