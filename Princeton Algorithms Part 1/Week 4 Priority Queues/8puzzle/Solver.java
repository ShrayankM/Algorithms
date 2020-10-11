import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.MinPQ;
import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdOut;

/*
* !https://www.cs.princeton.edu/courses/archive/fall12/cos226/assignments/8puzzle.html
* For unsolvable boards
* */

import java.util.Comparator;

public class Solver {

    private int moves;
    private boolean flag = false;
    private Stack<Board> q = new Stack<>();
    // find a solution to the initial board (using the A* algorithm)
    public Solver(Board initial) {
        if (initial == null) throw new IllegalArgumentException();
        NodeCompare cmp = new NodeCompare();

        Node init = new Node(null, initial);
        MinPQ<Node> pq = new MinPQ<>(cmp);

        pq.insert(init);
        // q.push(initial);
        while (!pq.isEmpty()) {
            Node t = pq.delMin();
            // q.enqueue(t.b);
            if (t.b.isGoal()) {
                moves = t.moves;
                while (t.prev != null) {
                        q.push(t.b);
                        t = t.prev;
                }
                q.push(initial);
                flag = true;
                break;
            }
            // moves++;
            for (Board n : t.b.neighbors()) {
                Node newNode = new Node(t, n);
                if (t.prev != null && t.prev.b.equals(newNode.b)) continue;
                pq.insert(newNode);
            }
        }
    }

    private class Node {

        // public int priority = 0;
        public int hamming = -1;
        public int manhattan = 0;
        public Board b;
        public int moves;
        public Node prev = null;
        Node(Node t, Board b) {
            this.b = b;
            this.manhattan = this.b.manhattan();
            this.hamming = this.b.hamming();
            // this.priority = this.b.manhattan() + moves;
            if (t != null) this.moves = this.moves + t.moves + 1;
            if (t != null) this.prev = t;
            else this.moves = 0;
        }
    }

    private class NodeCompare implements Comparator<Node> {

        public int compare(Node n1, Node n2) {
            if ((n1.manhattan + n1.moves) < (n2.manhattan + n2.moves)) return -1;
            if ((n1.manhattan + n1.moves) > (n2.manhattan + n2.moves)) return  1;

            // if (n1.hamming == -1) n1.hamming = n1.b.hamming();
            // if (n2.hamming == -1) n2.hamming = n2.b.hamming();

            if ((n1.hamming + n1.moves) < (n2.hamming + n2.moves)) return -1;
            if ((n1.hamming + n1.moves) > (n2.hamming + n2.moves)) return 1;
            return 0;
        }
    }


    // is the initial board solvable? (see below)
    public boolean isSolvable() {
        return flag;
    }

    // min number of moves to solve initial board; -1 if unsolvable
    public int moves() {
        return moves;
    }

    // sequence of boards in a shortest solution; null if unsolvable
    public Iterable<Board> solution() {
        return q;
    }

    // test client (see below) 
    public static void main(String[] args) {
        // create initial board from file
        In in = new In(args[0]);
        int n = in.readInt();
        int[][] tiles = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                tiles[i][j] = in.readInt();
        Board initial = new Board(tiles);

        // solve the puzzle
        Solver solver = new Solver(initial);

        // print solution to standard output
        if (!solver.isSolvable())
            StdOut.println("No solution possible");
        else {
            StdOut.println("Minimum number of moves = " + solver.moves());
            for (Board board : solver.solution())
                StdOut.println(board);
        }
    }

}