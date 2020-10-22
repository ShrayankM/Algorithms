import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.Stack;

public class BreathFirst {

    private boolean [] visited;
    private int [] edgeTo;
    private int [] distTo;
    private int source;

    BreathFirst(DiGraph g, int source) {
        this.source = source;
        visited = new boolean[g.V()];
        edgeTo = new int[g.V()];
        distTo = new int[g.V()];

        for (int i = 0; i < g.V(); i++) {
            visited[i] = false;
            edgeTo[i] = i; distTo[i] = 0;
        }

        bfs(g, source);
    }

    void bfs(DiGraph g, int s) {
        Queue<Integer> q = new Queue<>();
        q.enqueue(s);

        while (!q.isEmpty()) {
            s = q.dequeue();
            visited[s] = true;

            for (int vertex : g.adj(s)) {
                if (!visited[vertex]) {
                    q.enqueue(vertex);
                    edgeTo[vertex] = s;
                    distTo[vertex] = distTo[s] + 1;
                }
            }
        }
    }


    boolean hasPathTo(int v) {
        return visited[v];
    }

    Iterable<Integer> pathTo(int v) {
        Stack<Integer> st = new Stack<>();
        st.push(v);

        while (edgeTo[v] != v) {
            st.push(edgeTo[v]);
            v = edgeTo[v];
        }
        return st;
    }
}
