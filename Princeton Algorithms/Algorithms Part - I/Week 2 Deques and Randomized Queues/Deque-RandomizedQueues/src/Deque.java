import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {

    private Node start, end;
    private int count;

    public Deque() {
        count = 0;
        start = null;
        end = null;
    }

    public static void main(String[] args) {
        //empty body
    }

    @Override
    public Iterator<Item> iterator() {
        return new ForwardDeque();
    }

    public boolean isEmpty() {
        if (start == null && end == null)
            return true;
        return false;
    }

    public void addFirst(Item item) {
        if (item == null)
            throw new IllegalArgumentException();
        count++;
        Node n = new Node();
        n.data = item;
        if (start == null && end == null) {
            start = n;
            end = n;
        } else {
            n.next = start;
            start.previous = n;
            start = n;
        }
    }

    public void addLast(Item item) {
        if (item == null)
            throw new IllegalArgumentException();
        count++;
        Node n = new Node();
        n.data = item;
        if (start == null && end == null) {
            start = n;
            end = n;
        } else {
            n.previous = end;
            end.next = n;
            end = n;
        }
    }

    public Item removeFirst() {
        if (start == null && end == null)
            throw new NoSuchElementException();
        Node n = start;
        if (start == end) {
            start = null;
            end = null;
            count = 0;
        } else {
            count--;
            start = start.next;
            start.previous = null;
            n.next = null;
        }
        return n.data;
    }

    public Item removeLast() {
        if (start == null && end == null)
            throw new NoSuchElementException();
        Node n = end;
        if (start == end) {
            start = null;
            end = null;
            count = 0;
        } else {
            count--;
            end = end.previous;
            end.next = null;
            n.previous = null;
        }
        return n.data;
    }

    public int size() {
        return count;
    }

    private class Node {
        Item data;
        Node next = null;
        Node previous = null;
    }

    private class ForwardDeque implements Iterator<Item> {

        Node n = start;

        @Override
        public boolean hasNext() {
            return n != null;
        }

        @Override
        public Item next() {
            if (n == null)
                throw new NoSuchElementException();
            Item temp = n.data;
            n = n.next;
            return temp;
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }
}
