import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.RectHV;
import edu.princeton.cs.algs4.StdDraw;

import java.awt.Color;
import java.util.Comparator;

public class KdTree {

    private int pointCNT;
    private Node root;

    private Comparator<Point2D> xOrder = Point2D.X_ORDER;
    private Comparator<Point2D> yOrder = Point2D.Y_ORDER;

    private static class Node {
        private Point2D p;
        private RectHV rect;
        private Node left, right, parent;
        private int level;

        Node (Point2D p, int level) {
            this.level = level + 1;
            this.p = new Point2D(p.x(), p.y());
            left = null;
            right = null;
        }

    }

    // construct an empty set of points
    public KdTree() {
        root = null;
        pointCNT = 0;
    }

    // is the set empty?
    public boolean isEmpty() {
        return root == null;
    }

    // number of points in the set
    public int size() {
        return pointCNT;
    }

    // add the point to the set (if it is not already in the set)
    public void insert(Point2D p) {
        if (p == null) throw new IllegalArgumentException();
        if (root == null) {
            RectHV rect = new RectHV(0.0, 0.0, 1.0, 1.0);
            root = new Node(p, 0);
            root.rect = rect;
            pointCNT++;
            return;
        }
        root = insert(root, p, 0);
    }

    private Node insert(Node root, Point2D p, int level) {
        if (root == null) {
            pointCNT++;
            // RectHV rect = new RectHV()
            return new Node(p, level);
        }

        if (Point2D.X_ORDER.compare(root.p, p) == 0 && Point2D.Y_ORDER.compare(root.p, p) == 0) return root;

        int cmp;
        cmp = root.level % 2 == 1 ? xOrder.compare(root.p, p) : yOrder.compare(root.p, p);


        if (cmp > 0) {
            root.left = insert(root.left, p, root.level);
            if (root.left.rect == null) {
                if (root.level % 2 == 1)
                    root.left.rect = new RectHV(root.rect.xmin(), root.rect.ymin(), root.p.x(), root.rect.ymax());
                else
                    root.left.rect = new RectHV(root.rect.xmin(), root.rect.ymin(), root.rect.xmax(), root.p.y());
            }
        }
        else if (cmp <= 0) {
            root.right = insert(root.right, p, root.level);
            if (root.right.rect == null) {
                if (root.level % 2 == 1)
                    root.right.rect = new RectHV(root.p.x(), root.rect.ymin(), root.rect.xmax(), root.rect.ymax());
                else
                    root.right.rect = new RectHV(root.rect.xmin(), root.p.y(), root.rect.xmax(), root.rect.ymax());
            }
        }

        return root;
    }

    private Node contains(Node root, Point2D p) {
        if (root == null) return null;

        int cmp = (root.level % 2 == 1) ? xOrder.compare(root.p, p) : yOrder.compare(root.p, p);

        if (cmp == 0) {
            if (p.x() == root.p.x() && p.y() == root.p.y())
                return root;
            else return contains(root.right, p);
        }
        else if (cmp > 0) return contains(root.left, p);
        else return contains(root.right, p);

    }

    // does the set contain point p?
    public boolean contains(Point2D p) {
        if (p == null) throw new IllegalArgumentException();
        Node tp = root;
        Node rt = contains(tp, p);

        return rt != null;
    }

    private void preorder(Node root) {
        if (root != null) {
            StdDraw.setPenColor(Color.BLACK);
            StdDraw.setPenRadius(0.01);
            StdDraw.point(root.p.x(), root.p.y());

            // StdDraw.setPenColor(Color.LIGHT_GRAY);
            // StdDraw.filledRectangle(root.rect.xmin(), root.rect.ymin(), root.rect.width(), root.rect.height());

            // StdDraw.pause(1000);

            switch (root.level % 2) {
                case 1:
                    StdDraw.setPenColor(Color.RED);
                    StdDraw.setPenRadius(0.001);
                    StdDraw.line(root.p.x(), root.rect.ymin(), root.p.x(), root.rect.ymax());
                    break;
                default:
                    StdDraw.setPenColor(StdDraw.BLUE);
                    StdDraw.setPenRadius(0.001);
                    StdDraw.line(root.rect.xmax(), root.p.y(), root.rect.xmin(), root.p.y());
                    break;
            }

            // StdDraw.setPenColor(Color.WHITE);
            // StdDraw.filledRectangle(root.rect.xmin(), root.rect.ymin(), root.rect.width(), root.rect.height());
            preorder(root.left);
            preorder(root.right);
        }
    }

    // draw all points to standard draw
    public void draw()  {
        preorder(root);
    }

    private void checkRange(Node root, Queue<Point2D> q, RectHV rect) {
        if (root != null && rect.contains(root.p)) q.enqueue(root.p);
        if (root == null) return;
        if (root.left != null && root.left.rect.intersects(rect))
            checkRange(root.left, q, rect);

        if (root.right != null && root.right.rect.intersects(rect))
            checkRange(root.right, q, rect);
    }

    // all points that are inside the rectangle (or on the boundary)
    public Iterable<Point2D> range(RectHV rect)  {
        if (rect == null) throw new IllegalArgumentException();
        Node p = root;
        Queue<Point2D> q = new Queue<>();
        checkRange(p, q, rect);
        return q;
    }

    private Point2D findNear(Node root, Point2D p, Point2D champ, double dist) {
        if (root != null) {
            // System.out.println(root.p);
            double tDist = root.p.distanceSquaredTo(p);
            if (tDist < dist) {
                dist = tDist;
                champ = root.p;
            }

            if (root.left == null && root.right == null) return champ;

            if (root.left != null && root.left.rect.contains(p)) {
                Point2D rtChamp = findNear(root.left, p, champ, dist);
                if (rtChamp.distanceSquaredTo(p) < champ.distanceSquaredTo(p)) {
                    champ = rtChamp;
                    dist = rtChamp.distanceSquaredTo(p);
                }

                if (root.right != null && root.right.rect.distanceSquaredTo(p) < champ.distanceSquaredTo(p)) {
                    rtChamp = findNear(root.right, p, champ, dist);
                    if (rtChamp.distanceSquaredTo(p) < champ.distanceSquaredTo(p)) {
                        champ = rtChamp;
                        dist = rtChamp.distanceSquaredTo(p);
                    }
                }
            }
            else if (root.right != null && root.right.rect.contains(p)) {
                Point2D rtChamp = findNear(root.right, p, champ, dist);
                if (rtChamp.distanceSquaredTo(p) < champ.distanceSquaredTo(p)) {
                    champ = rtChamp;
                    dist = rtChamp.distanceSquaredTo(p);
                }

                if (root.left != null && root.left.rect.distanceSquaredTo(p) < champ.distanceSquaredTo(p)) {
                    rtChamp = findNear(root.left, p, champ, dist);
                    if (rtChamp.distanceSquaredTo(p) < champ.distanceSquaredTo(p)) {
                        champ = rtChamp;
                        dist = rtChamp.distanceSquaredTo(p);
                    }
                }
            }
            else {

                double lDist = Double.MAX_VALUE, rDist = Double.MAX_VALUE;
                if (root.left != null) lDist = root.left.rect.distanceSquaredTo(p);
                if (root.right != null) rDist = root.right.rect.distanceSquaredTo(p);

                // GOING LEFT
                if (lDist <= rDist && lDist < champ.distanceSquaredTo(p)) {
                    Point2D rtChamp = findNear(root.left, p, champ, dist);
                    if (rtChamp.distanceSquaredTo(p) < champ.distanceSquaredTo(p)) {
                        champ = rtChamp;
                        dist = rtChamp.distanceSquaredTo(p);
                    }

                    if (root.right != null && root.right.rect.distanceSquaredTo(p) < champ.distanceSquaredTo(p)) {
                        rtChamp = findNear(root.right, p, champ, dist);
                        if (rtChamp.distanceSquaredTo(p) < champ.distanceSquaredTo(p)) {
                            champ = rtChamp;
                            dist = rtChamp.distanceSquaredTo(p);
                        }
                    }
                }
                else if (rDist < champ.distanceSquaredTo(p)) {
                    Point2D rtChamp = findNear(root.right, p, champ, dist);
                    if (rtChamp.distanceSquaredTo(p) < champ.distanceSquaredTo(p)) {
                        champ = rtChamp;
                        dist = rtChamp.distanceSquaredTo(p);
                    }

                    if (root.left != null && root.left.rect.distanceSquaredTo(p) < champ.distanceSquaredTo(p)) {
                        rtChamp = findNear(root.left, p, champ, dist);
                        if (rtChamp.distanceSquaredTo(p) < champ.distanceSquaredTo(p)) {
                            champ = rtChamp;
                            dist = rtChamp.distanceSquaredTo(p);
                        }
                    }
                }

                // Point2D rtChamp = findNear(root.left, p, champ, dist);
                // if (rtChamp.distanceSquaredTo(p) < champ.distanceSquaredTo(p)) champ = rtChamp;
                //
                // if (root.right != null && root.right.rect.distanceSquaredTo(p) < champ.distanceSquaredTo(p)) {
                //     rtChamp = findNear(root.right, p, champ, dist);
                //     if (rtChamp.distanceSquaredTo(p) < champ.distanceSquaredTo(p)) champ = rtChamp;
                // }
            }
        }
        return champ;
    }


    // a nearest neighbor in the set to point p; null if the set is empty
    public Point2D nearest(Point2D p) {
        if (p == null) throw new IllegalArgumentException();
        Point2D champ = root.p;
        double dist = champ.distanceSquaredTo(p);
        champ = findNear(root, p, champ, dist);
        return champ;
    }

    // unit testing of the methods (optional)
    public static void main(String[] args) {

        String filename = args[0];
        In in = new In(filename);
        // PointSET brute = new PointSET();
        KdTree kdtree = new KdTree();
        while (!in.isEmpty()) {
            double x = in.readDouble();
            double y = in.readDouble();
            Point2D p = new Point2D(x, y);
            kdtree.insert(p);
            // brute.insert(p);
        }

        Point2D near = new Point2D(0.41, 0.03);
        // Point2D nearest = new Point2D(0.226, 0.577);

        StdDraw.setPenColor(Color.GREEN);
        StdDraw.setPenRadius(0.01);
        StdDraw.point(near.x(), near.y());

        // StdDraw.setPenColor(Color.ORANGE);
        // StdDraw.setPenRadius(0.01);
        // StdDraw.point(nearest.x(), nearest.y());

        Point2D rt = kdtree.nearest(near);


        System.out.println("Near: = " + rt + " DistanceSQ: = " + near.distanceSquaredTo(rt));
        kdtree.draw();

        // StdDraw.setPenColor(Color.ORANGE);
        // StdDraw.point(rt.x(), rt.y());
    }
}