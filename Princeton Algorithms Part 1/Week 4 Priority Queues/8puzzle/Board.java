import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Queue;

public class Board {

    private char [][] currentBoard;
    // private int [][] goalBoard;
    private int n;
    private int rIndex, cIndex;
    // private int [][] tiles;

    // create a board from an n-by-n array of tiles,
    // where tiles[row][col] = tile at (row, col)
    public Board(int[][] tiles) {

        n = tiles.length;
        // this.tiles = new int[n][n];
        currentBoard = new char[n + 1][n + 1];
        // goalBoard = new int[129][129];


        for (int i = 0; i < tiles.length; i++) {
            for (int j = 0; j < tiles.length; j++) {
                currentBoard[i + 1][j + 1] = (char) tiles[i][j];
                // this.tiles[i][j] = tiles[i][j];
                if (tiles[i][j] == 0) {
                    rIndex = i + 1;
                    cIndex = j + 1;
                }
            }
        }

        // int v = 1;
        // for (int i = 0; i < tiles.length; i++) {
        //     for (int j = 0; j < tiles.length; j++) {
        //         goalBoard[i + 1][j + 1] = v++;
        //     }
        // }
        // goalBoard[tiles.length][tiles.length] = 0;

    }

    // string representation of this board
    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append(n + "\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                s.append(String.format("%2d ", (int) currentBoard[i][j]));
            }
            s.append("\n");
        }
        return s.toString();
    }

    // board dimension n
    public int dimension() {
        return n;
    }

    // number of tiles out of place
    public int hamming() {
        int hDistance = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (currentBoard[i][j] == 0) continue;
                int v = (int) currentBoard[i][j];
                if (v == 0) continue;
                int r = (int) Math.ceil((double) v/ (double) n);
                int c = v % n;
                if (c == 0) c = n;
                if (i != r || j != c) hDistance++;
            }
        }
        return hDistance;
    }

    // sum of Manhattan distances between tiles and goal
    public int manhattan() {
        int mDistance = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int v = (int) currentBoard[i][j];
                if (v == 0) continue;
                int r = (int) Math.ceil((double) v/ (double) n);
                int c = v % n;
                if (c == 0) c = n;
                mDistance += Math.abs(i - r) + Math.abs(j - c);
            }
        }
        return mDistance;
    }

    // is this board the goal board?
    public boolean isGoal() {
        return hamming() == 0;
    }

    // does this board equal y?
    public boolean equals(Object y) {
        if (this == y) return true;
        if (y == null) return false;

        if (y.getClass() != this.getClass()) return false;

        Board that = (Board) y;
        if (this.n != that.n) return false;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // if (this.currentBoard[i][j] == 0) continue;
                if (this.currentBoard[i][j] != that.currentBoard[i][j])
                    return false;
            }
        }
        return true;
    }

    private Board getBoard(int c, int r, int nc, int nr) {
        if (nc <= 0 || nc > n) return null;
        if (nr <= 0 || nr > n) return null;
        int [][] tiles = new int[this.n][this.n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tiles[i][j] = this.currentBoard[i + 1][j + 1];
            }
        }
        Board newBoard = new Board(tiles);
        char temp = newBoard.currentBoard[nr][nc];
        newBoard.currentBoard[nr][nc] = newBoard.currentBoard[r][c];
        newBoard.currentBoard[r][c] = temp;

        newBoard.rIndex = nr;
        newBoard.cIndex = nc;

        // if (this.equals(newBoard)) return null;
        return newBoard;
    }

    // all neighboring boards
    public Iterable<Board> neighbors() {
        Queue<Board> q = new Queue<>();
        int [] prows = {rIndex + 1, rIndex - 1};
        int [] pcols = {cIndex + 1, cIndex - 1};
        Board b1 = getBoard(cIndex, rIndex, cIndex, prows[0]);
        Board b2 = getBoard(cIndex, rIndex, cIndex, prows[1]);
        Board b3 = getBoard(cIndex, rIndex, pcols[0], rIndex);
        Board b4 = getBoard(cIndex, rIndex, pcols[1], rIndex);

        if (b1 != null) q.enqueue(b1);
        if (b2 != null) q.enqueue(b2);
        if (b3 != null) q.enqueue(b3);
        if (b4 != null) q.enqueue(b4);

        return q;
    }

    // a board that is obtained by exchanging any pair of tiles
    public Board twin() {
        Board b = null;
        if (rIndex == 1 && cIndex == 1)
            b = getBoard(2, 1, 2, 2);
        else if (rIndex == 1 && cIndex == 2)
            b = getBoard(1, 1, 1, 2);
        else if (rIndex == 2 && cIndex == 1)
            b = getBoard(1, 1, 2, 1);
        else
            b = getBoard(1 , 1, 1, 2);
        return b;
    }

    // unit testing (not graded)
    public static void main(String[] args) {
        In in = new In(args[0]);
        int n = in.readInt();
        int[][] tiles = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                tiles[i][j] = in.readInt();
        Board t = new Board(tiles);
        Board t2 = new Board(tiles);

        System.out.println(t.equals(t2));
    }

}
