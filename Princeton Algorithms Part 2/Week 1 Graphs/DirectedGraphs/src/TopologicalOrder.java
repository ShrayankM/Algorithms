import edu.princeton.cs.algs4.Stack;
import java.util.Arrays;


public class TopologicalOrder {

    private boolean [] visited;
    private Stack<Integer> order;

    TopologicalOrder(DiGraph g) {
        CycleDetection cd = new CycleDetection(g);
        if (cd.hasCycle()) System.out.println("Cycle Present");
        else {
            order = new Stack<>();
            visited = new boolean[g.V()];
            Arrays.fill(visited, false);

            for (int i = 0; i < g.V(); i++) {
                if (!visited[i]) {
                    dfs(g, i);
                    order.push(i);
                }
            }
        }
    }

    void dfs(DiGraph g, int s) {
        visited[s] = true;

        for (int vertex : g.adj(s)) {
            if (!visited[vertex]) {
                dfs(g, vertex);
                order.push(vertex);
            }
        }
    }

    Iterable<Integer> tOrder() {
        return order;
    }
}
