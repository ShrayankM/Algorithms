
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;


public class PercolationStats {
    private static double confidence95 = 1.96;
    private double [] percolationValues;
    private int t;
    public PercolationStats(int n, int trials)
    {
        if (n <= 0 || trials <= 0)
            throw new IllegalArgumentException("Value must be greater than zero");
        else
        {
            t = trials;
            percolationValues = new double[trials];
            for (int i = 0; i < trials; i++)
            {
                Percolation perc = new Percolation(n);
                while (!perc.percolates())
                {
                    // System.out.println(1);
                    int row = StdRandom.uniform(1, n + 1);
                    int col = StdRandom.uniform(1, n + 1);
                    perc.open(row, col);
                }
                double den = (n * n);
                percolationValues[i] = perc.numberOfOpenSites()/den;
            }
            // for (int i = 1; i < percolationValues.length; i++)
            //     System.out.println(percolationValues[i]);
        }
    }

    public double mean()
    {
        return StdStats.mean(percolationValues);
    }

    public double stddev()
    {
        return StdStats.stddev(percolationValues);
    }

    public double confidenceLo()
    {
        double xBar = mean();
        double std = stddev();
        return xBar - (confidence95 * std)/Math.sqrt(t);
    }

    public double confidenceHi()
    {
        double xBar = mean();
        double std = stddev();
        return xBar + (confidence95 * std)/Math.sqrt(t);
    }

    public static void main(String[] args)
    {
        int n = Integer.parseInt(args[0]);
        int trials = Integer.parseInt(args[1]);
        PercolationStats persS = new PercolationStats(n, trials);
        System.out.println("mean = " + persS.mean());
        System.out.println("stddev = " + persS.stddev());
        System.out.println("95% confidence interval = [" + persS.confidenceLo() + ", " + persS.confidenceHi() + "]");
    }
}
