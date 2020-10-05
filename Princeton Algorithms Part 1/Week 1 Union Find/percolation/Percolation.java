

public class Percolation
{
    // private final WeightedQuickUnionUF object;
    private final UnionDisjoint object;
    private boolean [] checkOpen;
    private final int n;
    private int c;
    public Percolation(int n)
    {
        if (n <= 0)
            throw new IllegalArgumentException("Value must be greater than 0");
        // object = new WeightedQuickUnionUF(n * n + 2);
        object = new UnionDisjoint(n * n + 2);
        checkOpen = new boolean[n * n + 2];
        this.n = n;
        c = 0;
        for (int i = 1; i <= n; i++)
        {
            object.union(i, 0);
            object.union(n * n + 1 - i, n * n + 1);
        }
        for (int i = 1; i <= n * n; i++)
        {
            checkOpen[i] = false;
        }
    }
    private int getIndex(int row, int col)
    {
        return n * (row - 1) + col;
    }
    public void open(int row, int col)
    {
        if (row <= 0 || col <= 0)
            throw new IllegalArgumentException("Value greater than zero");
        else
        {
            int index = getIndex(row, col);
            if (checkOpen[index])
                return;
            checkOpen[index] = true;
            c++;
            if (col + 1 < n + 1 && checkOpen[index + 1])
            {
                object.union(index, index + 1);
            }
            if (col - 1 > 0 && checkOpen[index - 1])
            {
                object.union(index, index - 1);
            }
            if (row + 1 < n + 1 && checkOpen[index + n])
            {
                object.union(index, index + n);
            }
            if (row - 1 > 0 && checkOpen[index - n])
            {
                object.union(index, index - n);
            }
        }
    }
    public boolean isOpen(int row, int col)
    {
        if (row <= 0 || col <= 0)
            throw new IllegalArgumentException("Value greater than zero");
        else {
            int index = getIndex(row, col);
            if (checkOpen[index])
                return true;
            return false;
        }
    }

    public boolean isFull(int row, int col)
    {
        if (row <= 0 || col <= 0)
            throw new IllegalArgumentException("Value greater than zero");
        else
            {
                int index = getIndex(row, col);
                if (checkOpen[index] && (object.find(index) == object.find(0)))
                    return true;
                return false;
            }
    }
    public int numberOfOpenSites()
    {
        return c;
    }

    public boolean percolates()
    {
        if (object.find(0) == object.find(n * n + 1))
        {
            return true;
        }
        return false;
    }

    public static void main(String [] args)
    {
        // Called from PercolationStats.java
    }
}