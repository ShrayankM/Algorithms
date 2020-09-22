/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

public class UnionDisjoint {
    private int [] parent;
    private int [] size;
    public UnionDisjoint(int n)
    {
        parent = new int[n + 1];
        size = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 0;
        }
    }

    public int find(int i)
    {
        while (i != parent[i])
            i = parent[i];
        return i;
    }

    public void union(int i, int j)
    {
        if (find(i) == find(j))
            return;
        int pi = find(i);
        int pj = find(j);
        if (size[pi] < size[pj])
            parent[pi] = pj;
        else if (size[pi] > size[pj])
            parent[pj] = pi;
        else
        {
            parent[pi] = pj;
            size[pi]++;
        }

    }
    public static void main(String[] args) {

    }
}
