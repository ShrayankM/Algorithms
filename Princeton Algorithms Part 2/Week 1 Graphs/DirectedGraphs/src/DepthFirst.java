import edu.princeton.cs.algs4.Stack;
import java.util.Arrays;

public class DepthFirst {

    private boolean [] visited;
    private int [] edgeTo;
    private final int source;

    DepthFirst(DiGraph g, int source) {
        visited = new boolean[g.V()];
        edgeTo = new int[g.V()];
        this.source = source;

        Arrays.fill(visited, false);
        for (int i = 0; i < g.V(); i++) {
            edgeTo[i] = i;
        }

        dfs(g, source);
    }

    void dfs(DiGraph g, int s) {
        visited[s] = true;
        for (int vertex : g.adj(s)) {
            if (!visited[vertex]) {
                dfs(g, vertex);
                edgeTo[vertex] = s;
            }
        }
    }

    boolean hasPathTo(int v) {
        return visited[v];
    }

    Iterable<Integer> pathTo(int v) {
        Stack<Integer> st = new Stack<Integer>();
        st.push(v);
        while (edgeTo[v] != v) {
            st.push(edgeTo[v]);
            v = edgeTo[v];
        }
//        st.push(source);
        return st;
    }
}
