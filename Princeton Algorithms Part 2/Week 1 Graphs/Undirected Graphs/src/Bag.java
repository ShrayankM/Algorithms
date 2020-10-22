import java.util.Iterator;

public class Bag<Item> implements Iterable<Item> {

    private Node start;
    private int cnt = 0;

    // Node DS for Linked list implementation
    private class Node {
        Item data;
        Node next;

        Node(Item data) {
            this.data = data;
            this.next = null;
        }
    }

    // Constructor
    Bag() {
        this.start = null;
    }

    // Insert data in Bag (Front insert)
    public void insert(Item value) {
        cnt++;
        Node n = new Node(value);
        if (start == null) {
            start = n;
            return;
        }
        n.next = start;
        start = n;
    }

    // Update data in Bag
    public void update(Item value, Item nv) {
        if (start == null) return;
//        if (start.data == value) start.data = nv;

        Node p = start;
        while (p != null && p.data != value) p = p.next;
        if (p == null) return;
        p.data = nv;
    }


    private class BagIterator implements Iterator<Item> {

        Node p = start;
        @Override
        public boolean hasNext() {
            return p != null;
        }

        @Override
        public Item next() {
            Item t = p.data;
            p = p.next;
            return t;
        }
    }

    // No. of items in bag
    public int count() {
        return cnt;
    }

    @Override
    public Iterator<Item> iterator() {
        return new BagIterator();
    }
}
