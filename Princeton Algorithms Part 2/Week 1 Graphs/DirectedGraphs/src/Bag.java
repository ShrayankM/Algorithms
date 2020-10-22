import java.util.Iterator;

public class Bag<Item> implements Iterable<Item> {

    private Node start = null;

    private class Node {
        Item data;
        Node next;

        Node(Item data) {
            this.data = data;
            this.next = null;
        }
    }

    public void insert(Item key) {
        Node n = new Node(key);
        if (start == null) start = n;
        else {
            n.next = start;
            start = n;
        }
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
