import edu.princeton.cs.algs4.Digraph;

import java.util.Arrays;

public class CycleDetection {

    private boolean [] visited;
    private int [] edgeTo;
    private boolean hasCycle = false;
    private int vertices;

    public CycleDetection(Digraph G) {
        visited = new boolean[G.V() + 1];
        vertices = G.V();
        edgeTo = new int[G.V()];

        for (int i = 0; i < vertices; i++)
            edgeTo[i] = i;
        Arrays.fill(visited, false);

        for (int i = 0; i < G.V(); i++) {
            if (!visited[i]) {
                dfs(G, i, i);
            }
        }
    }

    private void dfs(Digraph G, int s, int source) {
        visited[s] = true;
        for (int vertex : G.adj(s)) {
            if (!visited[vertex]) {
                dfs(G, vertex, source);
                edgeTo[vertex] = s;
            }
            else if (vertex == source) hasCycle = true;
        }
    }

    public boolean graphHasCycle() {
        // if (hasCycle) return true;
        // int cnt = 0;
        // for (int i = 0; i < vertices; i++) {
        //     if (edgeTo[i] == i) cnt++;
        // }
        // if (cnt > 1) return true;
        // return false;
        return hasCycle;
    }

    public static void main(String[] args) {

    }
}
