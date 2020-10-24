import edu.princeton.cs.algs4.BreadthFirstDirectedPaths;
import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.In;

public class SAP {

    private final Digraph G;
    private static final int INFINITY = Integer.MAX_VALUE;

    // constructor takes a digraph (not necessarily a DAG)
    public SAP(Digraph G) {
        if (G == null) throw new IllegalArgumentException();
        this.G = new Digraph(G);
    }

    // length of shortest ancestral path between v and w; -1 if no such path
    public int length(int v, int w) {
        if (v < 0 || v > G.V()) throw new IllegalArgumentException();
        if (w < 0 || w > G.V()) throw new IllegalArgumentException();

        BreadthFirstDirectedPaths a = new BreadthFirstDirectedPaths(G, v);
        BreadthFirstDirectedPaths b = new BreadthFirstDirectedPaths(G, w);

        int minLen = INFINITY;
        for (int i = 0; i < G.V(); i++) {
            if (a.distTo(i) == INFINITY || b.distTo(i) == INFINITY) continue;
            int currentLen = a.distTo(i) + b.distTo(i);
            if (currentLen < minLen) {
                minLen = currentLen;
            }
        }

        // for (int i = 0; i < G.V(); i++) {
        //     System.out.println("From " + v + " to " + i + " distance = " + a.distTo(i));
        // }
        // System.out.println("----");
        // for (int i = 0; i < G.V(); i++) {
        //     System.out.println("From " + w + " to " + i + " distance = " + b.distTo(i));
        // }
        if (minLen == INFINITY) return -1;
        return minLen;
    }

    // a common ancestor of v and w that participates in a shortest ancestral path; -1 if no such path
    public int ancestor(int v, int w) {
        if (v < 0 || v > G.V()) throw new IllegalArgumentException();
        if (w < 0 || w > G.V()) throw new IllegalArgumentException();

        BreadthFirstDirectedPaths a = new BreadthFirstDirectedPaths(G, v);
        BreadthFirstDirectedPaths b = new BreadthFirstDirectedPaths(G, w);

        int ancestor = -1, minLen = INFINITY;
        for (int i = 0; i < G.V(); i++) {
            if (a.distTo(i) == INFINITY || b.distTo(i) == INFINITY) continue;
            int currentLen = a.distTo(i) + b.distTo(i);
            if (currentLen < minLen) {
                minLen = currentLen;
                ancestor = i;
            }
        }

        return ancestor;
        // return 0;
    }

    // length of shortest ancestral path between any vertex in v and any vertex in w; -1 if no such path
    public int length(Iterable<Integer> v, Iterable<Integer> w) {
        if (v == null || w == null) throw new IllegalArgumentException();

        int cntV = 0, cntW = 0;
        for (int i : v) cntV++;
        for (int i : w) cntW++;

        if (cntV == 0 || cntW == 0) throw new IllegalArgumentException();

        BreadthFirstDirectedPaths a = new BreadthFirstDirectedPaths(G, v);
        BreadthFirstDirectedPaths b = new BreadthFirstDirectedPaths(G, w);

        int minLen = INFINITY;
        for (int i = 0; i < G.V(); i++) {
            if (a.distTo(i) == INFINITY || b.distTo(i) == INFINITY) continue;
            int currentLen = a.distTo(i) + b.distTo(i);
            if (currentLen < minLen) {
                minLen = currentLen;
            }
        }
        if (minLen == INFINITY) return -1;
        return minLen;
    }

    // a common ancestor that participates in shortest ancestral path; -1 if no such path
    public int ancestor(Iterable<Integer> v, Iterable<Integer> w) {
        if (v == null || w == null) throw new IllegalArgumentException();

        int cntV = 0, cntW = 0;
        for (int i : v) cntV++;
        for (int i : w) cntW++;

        if (cntV == 0 || cntW == 0) throw new IllegalArgumentException();

        BreadthFirstDirectedPaths a = new BreadthFirstDirectedPaths(G, v);
        BreadthFirstDirectedPaths b = new BreadthFirstDirectedPaths(G, w);

        int ancestor = -1, minLen = INFINITY;
        for (int i = 0; i < G.V(); i++) {
            if (a.distTo(i) == INFINITY || b.distTo(i) == INFINITY) continue;
            int currentLen = a.distTo(i) + b.distTo(i);
            if (currentLen < minLen) {
                minLen = currentLen;
                ancestor = i;
            }
        }

        return ancestor;
    }

    // do unit testing of this class
    public static void main(String[] args) {
        String filename = args[0];
        In in = new In(filename);

        Digraph g = new Digraph(in);
        SAP sp = new SAP(g);

        int v = 3, w = 10;
        System.out.println("Ancestor of (" + v + ", " + w + ") = " + sp.ancestor(v, w));
        System.out.println("Length   of (" + v + ", " + w + ") = " + sp.length(v, w));
    }
}