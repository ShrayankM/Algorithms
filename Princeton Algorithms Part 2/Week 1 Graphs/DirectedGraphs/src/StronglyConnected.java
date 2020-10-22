import edu.princeton.cs.algs4.Stack;

import java.util.Arrays;

public class StronglyConnected {

    private boolean [] visited;
    private int [] scc;
    private int cnt = 0;
    private Stack<Integer> order;
    private int vertices;

    StronglyConnected(DiGraph g) {
        DiGraph gReverse = g.reverse();
        order = new Stack<>();
        scc = new int[g.V()];
        this.vertices = g.V();

        visited = new boolean[gReverse.V()];
        Arrays.fill(visited, false);

        for (int i = 0; i < gReverse.V(); i++) {
            if (!visited[i]) {
                dfsPostOrder(gReverse, i);
                order.push(i);
            }
        }

        visited = new boolean[g.V()];
        Arrays.fill(visited, false);

        while (!order.isEmpty()) {
            int vertex = order.pop();
            if (!visited[vertex]) {
                dfs(g, vertex);
                cnt++;
            }
        }
    }

    void dfsPostOrder(DiGraph g, int s) {
        visited[s] = true;

        for (int vertex : g.adj(s)) {
            if (!visited[vertex]) {
                dfsPostOrder(g, vertex);
                order.push(vertex);
            }
        }

    }

    void dfs(DiGraph g, int s) {
        visited[s] = true;
        scc[s] = cnt;

        for (int vertex : g.adj(s)) {
            if (!visited[vertex]) {
                dfs(g, vertex);
            }
        }
    }

    int totalComponents() {
        return cnt;
    }

    boolean isConnected(int v, int w) {
        return scc[v] == scc[w];
    }

    void viewComponents() {
        for (int i = 0; i < vertices; i++)
            System.out.print(i + " ");
        System.out.println();

        for (int i = 0; i < vertices; i++)
            System.out.print(scc[i] + " ");
        System.out.println();
    }
}
