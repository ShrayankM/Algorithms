import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.Stack;

import java.util.Arrays;

public class BreathFirst {

    boolean [] visited;
    int [] edgeTo;
    int [] distTo;
    int source;

    // constructor
    BreathFirst(Graph g, int source) {
        visited = new boolean[g.V()];
        edgeTo = new int[g.V()];
        distTo = new int[g.V()];
        this.source = source;

        Arrays.fill(visited, false);
        Arrays.fill(distTo, 0);
        bfs(g, source);
    }

    // recursive breadth-first implementation
    public void bfs(Graph g, int s) {
        Queue<Integer> q = new Queue<>();
        q.enqueue(s);
        visited[s] = true;

        while (!q.isEmpty()) {
            int p = q.dequeue();
            System.out.print(p + " ");
            for (int vertex : g.adj(p)) {
                if (!visited[vertex]) {
                    visited[vertex] = true;
                    edgeTo[vertex] = p;
                    distTo[vertex] = distTo[p] + 1;
                    q.enqueue(vertex);
                }
            }
        }
    }

    //  is there a path from source to v
    boolean hasPathTo(int v) {
        return visited[v];
    }

    // path from s to v, null if there is no such path
    Iterable<Integer> pathTo(int v) {
        Stack<Integer> st = new Stack<>();
        if (!this.hasPathTo(v)) return st;
        while (v != edgeTo[v]) {
            st.push(v);
            v = edgeTo[v];
        }
        st.push(source);
        return st;
    }

    // distance of v from source
    int distanceTo(int v) {
        return distTo[v];
    }
}
