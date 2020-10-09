public class BinarySearchTree<Key extends Comparable<Key>, Value> {

    private Node root = null;

    private class Node {
        Node left, right;
        Key key;
        Value value;

        Node(Key key, Value value) {
            this.key = key;
            this.value = value;
            left = null;
            right = null;
        }
    }

    public void insert(Key k, Value v) {
        root = insert(root, k, v);
    }

    private Node insert(Node p, Key k, Value v) {
        if (p == null) return new Node(k, v);
        int cmp = p.key.compareTo(k);
        if (cmp > 0)
            p.left = insert(p.left, k, v);
        else if (cmp < 0)
            p.right = insert(p.right, k, v);
        else p.value = v;
        return p;
    }

    public void inorder() {
        inorder(root);
    }

    private void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.println(root.key + "-->" + root.value);
            inorder(root.right);
        }
    }
}










