import java.util.Comparator;
import java.util.Arrays;

public class FastCollinearPoints {

    private LineSegment [] segments;
    private int c = 0;

    // finds all line segments containing 4 or more points
    public FastCollinearPoints(Point[] points) {
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
        ////////////////////////////////////////////////
        segments = new LineSegment[1];

        Point [] temp = new Point[points.length];
        System.arraycopy(points, 0, temp, 0, points.length);

        for (int i = 0; i < points.length; i++) {
            Point p = temp[i];
//            System.out.println("FirstP->>" + p);
            Comparator<Point> comp = p.slopeOrder();
            Arrays.sort(points, comp);

//            System.out.println("SecondP->>" + p);
            int j = 0;
            while (j < points.length) {
                double slopeT = p.slopeTo(points[j]);
                int k = j;
                j++;
                int cnt = 1;
//                System.out.println("ThirdP->>" + p);
                while (j < points.length && slopeT == p.slopeTo(points[j])) {
//                    if (p.compareTo(points[j]) != 0) {
//                        cnt++;
//                    }
                    cnt++;
                    j++;
                }
                if (cnt >= 3) {
//                    System.out.println("FourthP->>" + p);
                    Arrays.sort(points, k, k + cnt);
                    Point start, end;
                    if (p.compareTo(points[k]) < 0)
                        start = p;
                    else
                        start = points[k];

                    if (p.compareTo(points[k + cnt - 1]) > 0)
                        end = p;
                    else
                        end = points[k + cnt - 1];

                    LineSegment newS = new LineSegment(start, end);
//                    points[k] = null; points[k + cnt - 1] = null;
                    insertSegment(newS);
//                    break;
                }
            }
        }
    }

//    public void display(Point points[]) {
//        for (int i = 0; i < points.length; i++)
//            System.out.print(points[i] +" ");
//        System.out.println();
//    }


    private void insertSegment(LineSegment seg) {
        if (this.c == this.segments.length) {
            resize(this.c * 2);
        }

//        String segTry = seg.toString();
//        for (int i = 0; i < this.c; i++) {
//            String segStr = this.segments[i].toString();
//            if (segStr.compareTo(segTry) == 0)
//                return;
//        }
        this.segments[this.c] = seg;
        this.c++;
    }

    private void resize(int size) {
        LineSegment [] temp = new LineSegment[size];
        for (int i = 0; i < this.segments.length; i++) {
            temp[i] = this.segments[i];
        }
        this.segments = temp;
    }

    // the number of line segments
    public int numberOfSegments() {
       return segments().length;
    }

    private class LineCompare implements Comparator<LineSegment> {

        @Override
        public int compare(LineSegment L1, LineSegment L2) {
            return (L1.toString().compareTo(L2.toString()));
        }
    }

    public LineSegment[] segments() {
        LineSegment [] t = new LineSegment[this.c];

        Comparator<LineSegment> comp = new LineCompare();
        for (int i = 0; i < this.c; i++) {
            t[i] = this.segments[i];
        }

        Arrays.sort(t, comp);
        int cnt = 0, i = 0;
        while (i < t.length - 1) {
            int j = i + 1;
            while (j < t.length && t[i].toString().compareTo(t[j].toString()) == 0) {
                t[j] = null; j++;
                cnt++;
            }
            i = j;
        }
//        System.out.println(cnt);

        LineSegment [] nt = new LineSegment[this.c - cnt];
        int k = 0;
        for (int j = 0; j < t.length; j++) {
            if (t[j] == null)
                continue;
            nt[k++] = t[j];
        }
//        int j = -1;
//        for (int k = 0; k < nt.length; ) {
//            if (t[++j] == null)
//                continue;
//            nt[k++] = t[j];
//        }
        this.c = this.c - cnt;
        return nt;
    }
}