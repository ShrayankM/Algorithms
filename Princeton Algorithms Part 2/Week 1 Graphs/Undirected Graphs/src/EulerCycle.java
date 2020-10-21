import java.util.Arrays;

public class EulerCycle {

    // Condition 1: All vertices with non-zero degree have to be connected.
    // Condition 2: All non-zero vertices should have even degree. (0 vertices with odd degree)

    boolean [] visited;
    boolean eulerCycle = true;

    // check if EulerCycle present
    EulerCycle(Graph g) {
        visited = new boolean[g.V()];
        Arrays.fill(visited, false);

        // Condition 2: All non-zero vertices should have even degree
        for (int j = 0; j < g.V(); j++) {
            if (g.degree(j) % 2 == 1) eulerCycle = false;
        }

        if (eulerCycle) {
            int i = 0;
            while (g.degree(i) == 0) i++;

            // Condition 1: All vertices with non-zero degree have to be connected.
            dfs(g, i);
            for (int j = 0; j < g.V(); j++) {
                if (!visited[j] && g.degree(j) > 0) eulerCycle = false;
            }
        }
    }

    // simple dfs traversal
    void dfs(Graph g, int source) {
        visited[source] = true;
        for (int vertex : g.adj(source)) {
            if (!visited[vertex]) {
                dfs(g, vertex);
            }
        }
    }

    // check if cycle present
    boolean isPresent() {
        return eulerCycle;
    }
}
