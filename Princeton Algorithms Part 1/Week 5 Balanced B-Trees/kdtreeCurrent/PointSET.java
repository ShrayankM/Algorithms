import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.RectHV;
import edu.princeton.cs.algs4.SET;
import edu.princeton.cs.algs4.StdDraw;

public class PointSET {

    private SET<Point2D> pointsSET;

    // construct an empty set of points
    public PointSET() {
        pointsSET = new SET<Point2D>();
    }

    // is the set empty?
    public boolean isEmpty() {
        return pointsSET.isEmpty();
    }

    // number of points in the set
    public int size() {
        return pointsSET.size();
    }
    // add the point to the set (if it is not already in the set)
    public void insert(Point2D p) {
        if (p == null) throw new IllegalArgumentException();
        pointsSET.add(p);
    }

    // does the set contain point p?
    public boolean contains(Point2D p) {
        if (p == null) throw new IllegalArgumentException();
        return pointsSET.contains(p);
    }

    // draw all points to standard draw
    public void draw()  {
        for (Point2D p : pointsSET) {
            StdDraw.point(p.x(), p.y());
        }
    }

    // all points that are inside the rectangle (or on the boundary)
    public Iterable<Point2D> range(RectHV rect)  {
        if (rect == null) throw new IllegalArgumentException();
        Queue<Point2D> q = new Queue<>();

        for (Point2D p : pointsSET) {
            if ((p.x() >= rect.xmin() && p.x() <= rect.xmax()) && (p.y() >= rect.ymin()
                    && p.y() <= rect.ymax()))
                q.enqueue(p);
        }
        return q;
    }

    // a nearest neighbor in the set to point p; null if the set is empty
    public Point2D nearest(Point2D p) {
        if (p == null) throw new IllegalArgumentException();
        Point2D t = null;
        double dist = Double.MAX_VALUE;
        for (Point2D temp : pointsSET) {
            if (dist > p.distanceTo(temp)) {
                t = temp;
                dist = p.distanceTo((temp));
            }
        }
        return t;
    }

    // unit testing of the methods (optional)
    public static void main(String[] args) {
        // PointSET ps = new PointSET();
        // // Queue<Point2D> q = new Queue<>();
        // Point2D [] points = {new Point2D(2, 3), new Point2D(3, 2), new Point2D(5, 2),
        //                      new Point2D(5, 3), new Point2D(3, 4), new Point2D(3, 5),
        //                      new Point2D(2, 4), new Point2D(2, 5), new Point2D(3, 4)};
        // for (int i = 0; i < points.length; i++) {
        //     StdDraw.filledCircle(points[i].x() * 0.1, points[i].y() * 0.1, 0.01);
        //     ps.insert(new Point2D(points[i].x() * 0.1, points[i].y() * 0.1));
        // }
        //
        // Point2D neigh = ps.nearest(new Point2D(5, 2));
        // // StdDraw.filledCircle(neigh.x(), neigh.y(), 0.02);
        //
        // // RectHV rect = new RectHV(1.0, 1.0, 4.5, 4.5);
        // // StdDraw.rectangle(1.0, 1.0, 2.25, 2.25);
    }
}