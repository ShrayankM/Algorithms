import edu.princeton.cs.algs4.Stack;

import java.util.Arrays;

public class DepthFirst {

    boolean [] visited;
    int [] edgeTo;
    int source;

    // Constructor
    DepthFirst(Graph g, int source) {
        visited = new boolean[g.V()];
        edgeTo = new int[g.V()];

        for (int i = 0; i < g.V(); i++) edgeTo[i] = i;
        this.source = source;
        Arrays.fill(visited, false);
        dfs(g, source);
        System.out.println();
    }

    // recursive depth-first search implementation
    private void dfs(Graph g, int s) {
        System.out.print(s + " ");
        visited[s] = true;
        for (int vertex : g.adj(s)) {
            if (!visited[vertex]) {
                dfs(g, vertex);
                edgeTo[vertex] = s;
            }
        }
    }

    // is there a path from source to v
    boolean hasPathTo(int v) {
//        while (v != edgeTo[v]) v = edgeTo[v];
//        return v == source;
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
}
