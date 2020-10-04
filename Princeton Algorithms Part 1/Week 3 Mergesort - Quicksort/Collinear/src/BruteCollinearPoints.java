import java.util.Arrays;

public class BruteCollinearPoints {

    private LineSegment [] segments;
    private int c = 0;

    // finds all line segments containing 4 points
    public BruteCollinearPoints(Point[] points) {
        ///////////// Exception Handling ///////////////
        if (points == null)
            throw new IllegalArgumentException();

        for (int i = 0; i < points.length; i++) {
            if (points[i] == null)
                throw new IllegalArgumentException();
        }
        Point [] tempPoints = new Point[points.length];
        System.arraycopy(points, 0, tempPoints, 0, points.length);
        Arrays.sort(tempPoints);

        for (int i = 0; i < points.length - 1; i++) {
            if (tempPoints[i].compareTo(tempPoints[i + 1]) == 0)
                throw new IllegalArgumentException();
        }
        int pSize = points.length;
        segments = new LineSegment[1];
        for (int i = 0; i < pSize; i++) {
            for (int j = i + 1; j < pSize; j++) {
                for (int k = j + 1; k < pSize; k++) {
                    for (int m = k + 1; m < pSize; m++) {
                        Point p = points[i], q = points[j], r = points[k], s = points[m];
                        Point [] selected = {p, q, r, s};
                        Arrays.sort(selected);

                        if ((selected[0].slopeTo(selected[1]) == selected[0].slopeTo(selected[2]))
                                && selected[0].slopeTo(selected[1]) == selected[0].slopeTo(selected[3])) {
                            LineSegment newSeg = new LineSegment(selected[0], selected[3]);
                            insertSegment(newSeg);
                        }
                    }
                }
            }
        }
    }

    private void insertSegment(LineSegment seg) {
        if (this.c == this.segments.length) {
            resize(this.c * 2);
        }
        this.segments[this.c] = seg;
        this.c++;
    }

    private void resize(int size) {
        LineSegment[] temp = new LineSegment[size];
        for (int i = 0; i < this.segments.length; i++) {
            temp[i] = this.segments[i];
        }
        this.segments = temp;
    }

    // the number of line segments
    public int numberOfSegments() {
        return this.c;
    }

    // the line segments
    public LineSegment[] segments() {
        LineSegment[] t = new LineSegment[this.c];

        for (int i = 0; i < this.c; i++) {
            t[i] = this.segments[i];
        }
        return t;
    }


}