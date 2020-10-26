import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.Stack;

import java.util.Arrays;

public class TopologicalOrder {

    private Stack<Integer> tO;
    private EdgeWeightedDiGraph G;
    private boolean [] visited;

    TopologicalOrder(EdgeWeightedDiGraph G) {
        tO = new Stack<Integer>();
        this.G = G;
        visited = new boolean[G.V()];

        Arrays.fill(visited, false);

        for (int i = 0; i < G.V(); i++) {
            if (!visited[i]) {
                dfs(i);
                tO.push(i);
            }
        }
    }

    private void dfs(int s) {
        visited[s] = true;

        for (Edge e : G.adj(s)) {
            int v = e.getV(), w = e.getW(v);
            Vertex n;
            if (v == s) n = new Vertex(w, e.getWeight());
            else        n = new Vertex(v, e.getWeight());

            if (!visited[n.vertex()]) {
                dfs(n.vertex());
                tO.push(n.vertex());
            }
        }
    }

    public int startVertex() {
        return tO.peek();
    }

    public Iterable<Integer> tOrder() {
        return tO;
    }
}
