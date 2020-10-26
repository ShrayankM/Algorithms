import java.util.Iterator;

public class Bag<Item> implements Iterable<Item> {

    private Node head = null;
    private int cnt = 0;

    private class Node {
        Item data;
        Node next;

        Node (Item data) {
            this.data = data;
            next = null;
        }
    }

    public void add(Item data) {
        Node n = new Node(data);
        cnt++;
        if (head == null) {
            head = n;
            return;
        }
        n.next = head;
        head = n;
    }

    private class BagIterator implements Iterator<Item> {

        Node p = head;
        @Override
        public boolean hasNext() {
            return p != null;
        }

        @Override
        public Item next() {
            Item data = p.data;
            p = p.next;
            return data;
        }
    }

    public int count() {
        return cnt;
    }

    @Override
    public Iterator<Item> iterator() {
        return new BagIterator();
    }
}