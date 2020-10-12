import edu.princeton.cs.algs4.Queue;

public class RedBlackTree<Key extends Comparable<Key>,Value> {

    private final boolean RED = true;
    private final boolean BLACK = false;
    private Node root = null;

    class Node {
        Key key;
        Value value;
        Node left, right;
        boolean color;

        Node (Key k, Value v) {
            this.key = k;
            this.value = v;
            left = null;
            right = null;
            color = RED;
        }

    }

    public void insert(Key key, Value value) {
        root = insert(root, key, value);
        root.color = BLACK;
    }

    private Node insert(Node root, Key key, Value value) {

        if (root == null) return new Node(key, value);

        int cmp = root.key.compareTo(key);
        if (cmp < 0)      root.right = insert(root.right, key, value);
        else if (cmp > 0) root.left = insert(root.left, key, value);
        else              root.value = value;

        if (isRed(root.right) && !isRed(root.left)) root = rotateLeft(root);
        if (isRed(root.left) && isRed(root.left.left)) root = rotateRight(root);
        if (isRed(root.left) && isRed(root.right)) flipColors(root);
        return root;
    }

    public boolean isRed(Node n) {
        if (n == null) return false;
        return n.color == RED;
    }

    private Node rotateLeft(Node h) {
        Node x = h.right;
        h.right = x.left;
        x.left = h;
        x.color = h.color;
        h.color = RED;
        return x;
    }

    private Node rotateRight(Node h) {
        Node x = h.left;
        h.left = x.right;
        x.right = h;
        x.color = h.color;
        h.color = RED;
        return x;
    }

    private void flipColors(Node h) {
        h.color = RED;
        h.left.color = BLACK;
        h.right.color = BLACK;
    }

//    private void inorder(Node root, Queue<Key> q) {
//        if (root != null) {
//            inorder(root.left, q);
//            q.enqueue(root.key);
//            inorder(root.right, q);
//        }
//    }

    private void preorder(Node root, Queue<Key> q) {
        if (root != null) {
            q.enqueue(root.key);
            preorder(root.left, q);
            preorder(root.right, q);
        }
    }

    public Iterable<Key> keys() {
        Queue<Key> q = new Queue<>();
//        inorder(root, q);
        preorder(root, q);
        return q;
    }
}
