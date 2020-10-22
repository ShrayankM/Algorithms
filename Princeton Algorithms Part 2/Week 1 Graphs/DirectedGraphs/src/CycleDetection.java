import edu.princeton.cs.algs4.Stack;

import java.util.Arrays;

public class CycleDetection {
    private boolean [] visited;
    private boolean hasCycle = false;

    CycleDetection(DiGraph g) {
        visited = new boolean[g.V()];
        Arrays.fill(visited, false);

        for (int i = 0; i < g.V(); i++) {
            if (!visited[i]) {
                dfs(g, i, i);
            }
        }
//        dfs(g);
    }

    void dfs(DiGraph g, int s, int source) {
        visited[s] = true;
        for (int vertex : g.adj(s)) {
            if (!visited[vertex]) {
                dfs(g, vertex, source);
            }
            else if (vertex == source) hasCycle = true;
        }
    }

    boolean hasCycle() {
        return hasCycle;
    }
}
