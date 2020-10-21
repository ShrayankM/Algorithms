import java.util.Arrays;

public class ConnectedComponents {

    boolean [] visited;
    int [] cId;
    int cnt;

    // Constructor (find connected components in g)
    ConnectedComponents(Graph g) {
        cId = new int[g.V()];
        visited = new boolean[g.V()];
        Arrays.fill(visited, false);

        cnt = 0;

        for (int i = 0; i < g.V(); i++) {
            if (!visited[i]) {
                dfs(g, i);
                cnt++;
            }
        }
    }

    // are v and w connected ?
    boolean connected(int v, int w) {
        return cId[v] == cId[w];
    }

    // number of connected components
    int count() {
        return cnt + 1;
    }

    // component identifier for v
    int id(int v) {
        return cId[v];
    }

    // depth-first search algorithm
    void dfs(Graph g, int s) {
        visited[s] = true;
        cId[s] = cnt;
        for (int vertex : g.adj(s)) {
            if (!visited[vertex]) {
                dfs(g, vertex);
            }
        }
    }
}
