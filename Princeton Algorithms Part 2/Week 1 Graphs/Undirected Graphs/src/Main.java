import edu.princeton.cs.algs4.In;

import java.util.Iterator;

public class Main {

    public static void main(String[] args) {

        String filename = args[0];
        In in = new In(filename);
        Graph g = new Graph(in);

        BreathFirst bfs = new BreathFirst(g, 0);
        System.out.println();
        for (int vertex : bfs.pathTo(2)) {
            System.out.print(vertex + " ");
        }
        System.out.println();

        System.out.println(bfs.distanceTo(4));
    }
}
