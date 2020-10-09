import edu.princeton.cs.algs4.Queue;

public class BinarySearchTree<Key extends Comparable<Key>, Value> {

    private Node root = null;

    private class Node {
        Node left, right;
        Key key;
        Value value;
        int count;

        Node(Key key, Value value, int count) {
            this.key = key;
            this.value = value;
            left = null;
            right = null;
            this.count = count;
        }
    }

    public void insert(Key k, Value v) {
        root = insert(root, k, v);
    }

    private Node insert(Node p, Key k, Value v) {
        if (p == null) return new Node(k, v, 1);
        int cmp = p.key.compareTo(k);
        if (cmp > 0)
            p.left = insert(p.left, k, v);
        else if (cmp < 0)
            p.right = insert(p.right, k, v);
        else p.value = v;
        p.count = 1 + size(p.left) + size(p.right);
        return p;
    }

    private Node inorder_succ(Node r) {
        while (r != null && r.left != null)
            r = r.left;
        return r;
    }

    public void delete(Key k) {
        root = delete(root, k);
    }

    private Node delete(Node p, Key k) {
        int cmp = p.key.compareTo(k);
        if (cmp > 0)
            p.left = delete(p.left, k);
        else if (cmp < 0)
            p.right = delete(p.right, k);
        else {
            if (p.left == null)  return p.right;
            if (p.right == null) return p.left;

            Node sNode = inorder_succ(p.right);
            p.value = sNode.value;
            p.key = sNode.key;
            p.count = sNode.count;
            p.right = delete(p.right, sNode.key);
        }
        p.count = 1 + size(p.left) + size(p.right);
        return p;
    }

    public Key floor(Key k) {
        Node x = floor(root, k);
        if (x == null) return null;
        return x.key;
    }

    private Node floor(Node p, Key k) {

        if (p == null) return null;
        int cmp = p.key.compareTo(k);

        if (cmp == 0) return p;

        if (cmp > 0) return floor(p.left, k);

        Node t = floor(p.right, k);
        if (t != null) return t;
        return p;
    }

    public Key ceil(Key k) {
        Node x = ceil(root, k);
        if (x == null) return null;
        return x.key;
    }

    private Node ceil(Node p, Key k) {

        if (p == null) return null;
        int cmp = p.key.compareTo(k);

        if (cmp == 0) return p;

        if (cmp < 0) return ceil(p.right, k);

        Node t = ceil(p.left, k);
        if (t != null) return t;
        return p;

    }

    public int size() {
        return size(root);
    }

    private int size(Node root) {
        if (root == null) return 0;
        return root.count;
    }

    public int rank(Key k) {
        return rank(root, k);
    }

    private int rank(Node p, Key k) {
        if (p == null) return 0;

        int cmp = p.key.compareTo(k);
        if (cmp > 0) return rank(p.left, k);
        if (cmp < 0) return 1 + size(p.left) + rank(p.right, k);
        return size(p.left);
    }

//    public void inorder() {
//        inorder(root);
//    }

    private void inorder(Node root, Queue<Key> q) {
        if (root != null) {
            inorder(root.left, q);
//            System.out.print(root.key + " ");
            q.enqueue(root.key);
            inorder(root.right, q);
        }
    }

    public Iterable<Key> keys() {
        Queue<Key> q = new Queue<>();
        inorder(root, q);
        return q;
    }
}










