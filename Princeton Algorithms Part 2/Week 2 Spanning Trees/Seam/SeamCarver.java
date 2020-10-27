import edu.princeton.cs.algs4.Picture;

public class SeamCarver {

    private Picture picture;
    private double [][] energyPixel;
    private int height, width;
    // private Position edgeTo[][];
    // public double distTo[][];
    private double INF = Double.MAX_VALUE;
    private boolean transpose = false;

    // create a seam carver object based on the given picture
    public SeamCarver(Picture picture) {
        if (picture == null) throw new IllegalArgumentException();
        this.picture = new Picture(picture);
        energyPixel = new double[picture.height()][picture.width()];

        this.height = picture.height();
        this.width = picture.width();

        // edgeTo = new Position[height][width];
        // distTo = new double[height][width];

        // for (int i = 0; i < height; i++)
        //     for (int j = 0; j < width; j++)
        //         distTo[i][j] = INF;

        calculateEnergy();

        // for (int i = 0; i < width; i++) distTo[0][i] = energyPixel[0][i];

        // displayEnergy();
    }

    private void initDist(double distTo[][]) {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                distTo[i][j] = INF;

        for (int i = 0; i < width; i++) distTo[0][i] = energyPixel[0][i];
    }

    private void calculateEnergy() {

        // energyPixel = new double[picture.height()][picture.width()];
        // For FirstRow, LastRow
        for (int i = 0; i < width; i++) {
            energyPixel[0][i] = 1000.0;
            energyPixel[height - 1][i] = 1000.0;
        }

        // For FirstColumn, LastColumn
        for (int i = 0; i < height; i++) {
            energyPixel[i][0] = 1000.0;
            energyPixel[i][width - 1] = 1000.0;
        }

        for (int i = 1; i < height - 1; i++) {
            for (int j = 1; j < width - 1; j++) {
                double deltaX = calculateDeltaX(j, i);
                double deltaY = calculateDeltaY(j, i);
                energyPixel[i][j] = Math.sqrt(deltaX + deltaY);
            }
        }
    }

    private void displayEnergy() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                System.out.print(String.format("%.2f ", energyPixel[i][j]));
            }
            System.out.println();
        }
    }

    private double calculateDeltaX(int col, int row) {
        int rLeft, gLeft, bLeft;
        int rRight, gRight, bRight;

        rLeft = picture.getRGB(col - 1, row) >> 16 & 0xFF;
        gLeft = picture.getRGB(col - 1, row) >> 8 & 0xFF;
        bLeft = picture.getRGB(col - 1, row) >> 0 & 0xFF;

        rRight = picture.getRGB(col + 1, row) >> 16 & 0xFF;
        gRight = picture.getRGB(col + 1, row) >> 8 & 0xFF;
        bRight = picture.getRGB(col + 1, row) >> 0 & 0xFF;

        return Math.pow(rLeft - rRight, 2) + Math.pow(gLeft - gRight, 2) + Math.pow(bLeft - bRight, 2);

    }

    private double calculateDeltaY(int col, int row) {
        int rTop, gTop, bTop;
        int rBottom, gBottom, bBottom;

        rTop = picture.getRGB(col, row - 1) >> 16 & 0xFF;
        gTop = picture.getRGB(col, row - 1) >> 8 & 0xFF;
        bTop = picture.getRGB(col, row - 1) >> 0 & 0xFF;

        rBottom = picture.getRGB(col, row + 1) >> 16 & 0xFF;
        gBottom = picture.getRGB(col, row + 1) >> 8 & 0xFF;
        bBottom = picture.getRGB(col, row + 1) >> 0 & 0xFF;

        return Math.pow(rTop - rBottom, 2) + Math.pow(gTop - gBottom, 2) + Math.pow(bTop - bBottom, 2);

    }

    // current picture
    public Picture picture() {
        return picture;
    }

    // width of current picture
    public int width() {
        return picture.width();
    }

    // height of current picture
    public int height() {
        return picture.height();
    }

    // energy of pixel at column x and row y
    public double energy(int x, int y) {
        if (x < 0 || x >= picture.width())  throw new IllegalArgumentException();
        if (y < 0 || y >= picture.height()) throw new IllegalArgumentException();
        return energyPixel[y][x];
    }

    private void doTranspose() {
        double [][] energyT = new double[this.width][this.height];

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                energyT[j][i] = energyPixel[i][j];
            }
        }

        energyPixel = energyT;
        int temp = this.height;
        this.height = this.width;
        this.width = temp;
    }

    // // sequence of indices for horizontal seam
    public int[] findHorizontalSeam() {
        doTranspose();
        transpose = true;
        int result[] = findVerticalSeam();

        // System.out.println("----------------- Horizontal Seam Details -------------------");
        //
        // for (int i = 0; i < result.length; i++) System.out.print(result[i] + " ");
        // System.out.println();
        // double minEnergy = 0.0;
        // for (int i = 0; i < result.length; i++) {
        //     System.out.print(String.format("%.2f ", energyPixel[i][result[i]]));
        //     minEnergy += energyPixel[i][result[i]];
        // }
        // System.out.println();
        // System.out.println(String.format("Min Energy = %.2f ", minEnergy));
        doTranspose();
        transpose = false;
        return result;
    }

    // sequence of indices for vertical seam
    public int[] findVerticalSeam() {

        double [][] distTo = new double[height][width];
        Position [][] edgeTo = new Position[height][width];
        initDist(distTo);

        for (int i = width - 1; i >= 0; i--) {
            for (int j = i, k = 0; (j < width && k < height); j++, k++) {
                process(k, j, distTo, edgeTo);
            }
        }

        for (int i = 1; i < height; i++) {
            for (int j = i, k = 0; (j < height && k < width); j++, k++) {
                process(j, k, distTo, edgeTo);
            }
        }

        int minCol = 0;
        double dist = Double.MAX_VALUE;

        for (int i = 0; i < width; i++) {
            if (dist > distTo[height - 1][i]) {
                dist = distTo[height - 1][i];
                minCol = i;
            }
        }

        int [] result = new int[height];
        int start = height;
        while (start != 0) {
            start--;
            result[start] = minCol;
            if (start == 0) break;
            minCol = edgeTo[start][minCol].getCol();
        }

        // int rt[] = new int[result.length - 1];
        // for (int i = 1; i < result.length; i++) rt[i - 1] = result[i];

        // viewDistance(distTo);

        // if (!transpose) {
        //     System.out.println("----------------- Vertical Seam Details -------------------");
        //
        //     for (int i = 0; i < result.length; i++) System.out.print(result[i] + " ");
        //     System.out.println();
        //     double minEnergy = 0.0;
        //     for (int i = 0; i < result.length; i++) {
        //         System.out.print(String.format("%.2f ", energyPixel[i][result[i]]));
        //         minEnergy += energyPixel[i][result[i]];
        //     }
        //     System.out.println();
        //     System.out.println(String.format("Min Energy = %.2f ", minEnergy));
        // }
        return result;

    }

    private void process(int row, int col, double [][] distTo, Position [][] edgeTo) {
        // forward
        if (row + 1 < height && col + 1 < width) {
            if (distTo[row + 1][col + 1] > distTo[row][col] + energyPixel[row + 1][col + 1]) {
                distTo[row + 1][col + 1] = distTo[row][col] + energyPixel[row + 1][col + 1];
                edgeTo[row + 1][col + 1] = new Position(row, col);
            }
        }

        // bottom
        if (row + 1 < height) {
            if (distTo[row + 1][col] > distTo[row][col] + energyPixel[row + 1][col]) {
                distTo[row + 1][col] = distTo[row][col] + energyPixel[row + 1][col];
                edgeTo[row + 1][col] = new Position(row, col);
            }
        }

        // backward
        if (row + 1 < height && col - 1 >= 0) {
            if (distTo[row + 1][col - 1] > distTo[row][col] + energyPixel[row + 1][col - 1]) {
                distTo[row + 1][col - 1] = distTo[row][col] + energyPixel[row + 1][col - 1];
                edgeTo[row + 1][col - 1] = new Position(row, col);
            }
        }
    }

    private void doTransposePicture() {
        Picture picT = new Picture(this.height, this.width);

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                picT.setRGB(i, j, picture.getRGB(j, i));
            }
        }

        picture = picT;
        int temp = this.height;
        this.height = this.width;
        this.width = temp;
    }

    // remove horizontal seam from current picture
    public void removeHorizontalSeam(int[] seam) {
        if (seam == null) throw new IllegalArgumentException();
        if (seam.length > picture.width() || seam.length < picture.width()) throw new IllegalArgumentException();
        for (int i = 1; i < seam.length; i++) {
            if (Math.abs(seam[i - 1] - seam[i]) > 1) throw new IllegalArgumentException();
        }

        if (picture.height() == 1) throw new IllegalArgumentException();

        Picture modP = new Picture(this.width, this.height - 1);
        int col = 0;
        for (int i = 0; i < seam.length; i++) {
            int row = seam[i];

            if (row < 0 || row > picture.height()) throw new IllegalArgumentException();

            for (int j = 0; j < row; j++) modP.setRGB(col, j, picture.getRGB(col, j));
            for (int j = row; j < modP.height(); j++) modP.setRGB(col, j, picture.getRGB(col, j + 1));

            col++;
        }

        picture = modP;
        this.width = picture.width();
        this.height = picture.height();

        calculateEnergy();
    }

    // remove vertical seam from current picture
    public void removeVerticalSeam(int[] seam) {
        if (seam == null) throw new IllegalArgumentException();
        if (seam.length > picture.height() || seam.length < picture.height()) throw new IllegalArgumentException();

        for (int i = 1; i < seam.length; i++) {
            if (Math.abs(seam[i - 1] - seam[i]) > 1) throw new IllegalArgumentException();
        }

        if (picture.width() == 1) throw new IllegalArgumentException();
        Picture modP = new Picture(this.width - 1, this.height);
        int row = 0;
        for (int i = 0; i < seam.length; i++) {
            int col = seam[i];

            if (col < 0 || col > picture.width()) throw new IllegalArgumentException();

            for (int j = 0; j < col; j++) modP.setRGB(j, row, picture.getRGB(j, row));
            for (int j = col; j < modP.width(); j++) modP.setRGB(j, row, picture.getRGB(j + 1, row));
            row++;
        }

        picture = modP;
        this.width = picture.width();
        this.height = picture.height();

        calculateEnergy();
    }

    private void viewDistance(double distTo[][]) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                System.out.print(String.format("%.2f ", distTo[i][j]));
            }
            System.out.println();
        }
    }

    //  unit testing (optional)
    public static void main(String[] args) {
        String filename = args[0];
        Picture p = new Picture(filename);
        //
        SeamCarver sc = new SeamCarver(p);
        //
        // int resultV[] = sc.findVerticalSeam();
        // int resultH[] = sc.findHorizontalSeam();
        //
        // sc.removeVerticalSeam(resultV);

        System.out.println(sc.energy(1, 2));
        System.out.println(sc.energy(4, 5));

    }

}