import java.util.Iterator;

public class Bag<Item> implements Iterable<Item> {

    private Node head = null;
    private int cnt = 0;

    private class Node {
        Item data;
        Node next;

        Node(Item data) {
            this.data = data;
            this.next = null;
        }
    }

    public void add(Item data) {
        cnt++;
        Node n = new Node(data);
        if (head == null) head = n;
        else {
            n.next = head;
            head = n;
        }
    }

    private class BagIterator implements Iterator<Item> {

        Node p = head;
        @Override
        public boolean hasNext() {
            return p != null;
        }

        @Override
        public Item next() {
            Item d = p.data;
            p = p.next;
            return d;
        }
    }

    @Override
    public Iterator<Item> iterator() {
        return new BagIterator();
    }

    public int count() {
        return cnt;
    }
}
