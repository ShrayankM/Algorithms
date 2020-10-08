/* *****************************************************************************
 *  Name: Shrayank Mistry
 *  Date: 07/10/2020
 *  Description: Princeton 8 puzzle assignment
 **************************************************************************** */

public class Board {

    private int [][] currentBoard;
    private int [][] goalBoard;
    private int n;
    // create a board from an n-by-n array of tiles,
    // where tiles[row][col] = tile at (row, col)
    public Board(int[][] tiles) {
        currentBoard = new int[129][129];
        goalBoard = new int[129][129];

        n = tiles.length;
        for (int i = 0; i < tiles.length; i++) {
            for (int j = 0; j < tiles.length; j++) {
                currentBoard[i + 1][j + 1] = tiles[i][j];
            }
        }

        int v = 1;
        for (int i = 0; i < tiles.length; i++) {
            for (int j = 0; j < tiles.length; j++) {
                goalBoard[i + 1][j + 1] = v++;
            }
        }
        goalBoard[tiles.length - 1][tiles.length - 1] = 0;

    }

    // string representation of this board
    public String toString() {

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
                if (currentBoard[i][j] != goalBoard[i][j]) hDistance++;
            }
        }
        return hDistance;
    }

    // sum of Manhattan distances between tiles and goal
    public int manhattan() {
        int mDistance = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

            }
        }
    }

    // is this board the goal board?
    public boolean isGoal() {
        return hamming() == 0;
    }

    // does this board equal y?
    public boolean equals(Object y) {

    }

    // all neighboring boards
    public Iterable<Board> neighbors() {

    }

    // a board that is obtained by exchanging any pair of tiles
    public Board twin() {

    }

    // unit testing (not graded)
    public static void main(String[] args) {

    }

}
