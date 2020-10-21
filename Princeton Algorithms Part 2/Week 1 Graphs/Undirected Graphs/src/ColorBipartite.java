import edu.princeton.cs.algs4.Queue;

import java.util.Arrays;

public class ColorBipartite {

    boolean [] color;
    boolean [] visited;
    boolean isBipartite = true;

    ColorBipartite(Graph g) {
        color = new boolean[g.V()];
        visited = new boolean[g.V()];
        Arrays.fill(visited, false);

        for (int i = 0; i < g.V(); i++) {
            if (!visited[i]) bfs(g, i);
        }
    }

    void bfs(Graph g, int s) {
        Queue<Integer> q = new Queue<>();
        q.enqueue(s);

        while (!q.isEmpty()) {
            int v = q.dequeue();
            visited[v] = true;

            for (int vertex : g.adj(v)) {
                if (!visited[vertex]) {
                    color[vertex] = !color[v];
                    q.enqueue(vertex);
                }
                else if (color[vertex] == color[v]) isBipartite = false;
            }
        }
    }

    boolean isBipartite() {
        return isBipartite;
    }
}
