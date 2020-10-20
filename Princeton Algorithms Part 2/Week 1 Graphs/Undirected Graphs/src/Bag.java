import java.util.Iterator;

public class Bag<Item> implements Iterable<Item> {

    private Node start;

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
        Node n = new Node(value);
        if (start == null) {
            start = n;
            return;
        }
        n.next = start;
        start = n;
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

    @Override
    public Iterator<Item> iterator() {
        return new BagIterator();
    }
}
