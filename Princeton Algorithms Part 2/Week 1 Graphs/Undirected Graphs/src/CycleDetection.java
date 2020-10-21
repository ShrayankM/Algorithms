public class CycleDetection {

    boolean [] visited;
    boolean hasCycle;

    // do depth-first search to check for cycles
    CycleDetection(Graph g) {
        visited = new boolean[g.V()];
        hasCycle = false;
        for (int i = 0; i < g.V(); i++) {
            if (!visited[i]) {
                dfs(g, i, i);
            }
        }
    }

    // modified dfs algorithm
    void dfs(Graph g, int v, int source) {
        visited[v] = true;
        for (int vertex : g.adj(v)) {
            if (!visited[vertex]) dfs(g, vertex, v);
            else if (vertex != source) hasCycle = true;
        }
    }

    boolean cyclePresent() {
        return hasCycle;
    }
}
