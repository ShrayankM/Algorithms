import edu.princeton.cs.algs4.Queue;

import java.util.Arrays;

public class FindEulerPath {

    Graph gh;
    FindEulerPath(Graph g) {

        gh = g;
        EulerPath ep = new EulerPath(g);
        if (!ep.isPresent()) {
            System.out.println("Path does not exists:");
            return;
        }

        int u, i;
        for (i = 0; i < gh.V(); i++) {
            if (gh.degree(i) % 2 == 1) break;
        }

        if (i == gh.V()) u = 0;
        else            u = i;

        findPath(u);
    }

    void findPath(int u) {
        for (int v : gh.adj(u)) {
            if (v  != -1 && isValidEdge(u, v)) {
                System.out.println(u + "--" + v);
                removeEdge(u, v);
                findPath(v);
            }
        }
    }

    boolean isValidEdge(int u, int v) {
        int cnt = 0;
        for (int vertex : gh.adj(u)) {
            if (vertex != -1) cnt++;
        }
        if (cnt == 1) return true;

        boolean [] visited = new boolean[gh.V()];
        Arrays.fill(visited, false);
        int countOne = bfsCount(u, visited);

        removeEdge(u, v);
        Arrays.fill(visited, false);
        int countTwo = bfsCount(u, visited);

        addEdge(u, v);

        if (countOne > countTwo) return false;
        return true;
    }


    int bfsCount(int v, boolean [] visited) {
        visited[v] = true;
        int cnt = 0;

        Queue<Integer> q = new Queue<>();
        q.enqueue(v);

        while (!q.isEmpty()) {
            v = q.dequeue();
            cnt++;
            for (int vertex : gh.adj(v)) {
                if (vertex != -1 && !visited[vertex]) {
                    visited[vertex] = true;
                    q.enqueue(vertex);
                }
            }
        }
        return cnt;
    }

    void removeEdge(int u, int v) {
        gh.removeEdge(u, v);
    }

    void addEdge(int u, int v) {
        gh.addEdge(u, v);
    }
}
