import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Objects;

import edu.princeton.cs.algs4.StdRandom;

public class RandomizedQueueList<Item> implements Iterable<Item> {

    private int [] array;

    private Node start;
    private int count;

    // construct an empty randomized queue
    public RandomizedQueueList() {
        start = null;
        count = 0;
    }

    // unit testing (required)
    public static void main(String[] args) {
        //empty body
    }

    // is the randomized queue empty?
    public boolean isEmpty() {
        if (start == null)
            return true;
        return false;
    }

    // return the number of items on the randomized queue
    public int size() {
        return count;
    }

    // add the item
    public void enqueue(Item item) {
        if (item == null)
            throw new IllegalArgumentException();
        count++;
        Node n = new Node();
        n.data = item;
        if (start == null) {
            start = n;
        } else {
            n.next = start;
            start = n;
        }
    }

    // remove and return a random item
    public Item dequeue() {
        if (start == null)
            throw new NoSuchElementException();
        int index = StdRandom.uniform(1, count + 1);
//        System.out.println(index);
        count--;
        index--;
        if (index == 0) {
            Item temp = start.data;
            start = start.next;
            return temp;
        }
        else {
            int j = 1;
            Node itr = start;
            while (index > 0 && j != index) {
                itr = itr.next;
                j++;
            }
            Node n = itr.next;
            itr.next = n.next;
            n.next = null;
            return n.data;
        }
    }

    // return a random item (but do not remove it)
    public Item sample() {
        if (start == null)
            throw new NoSuchElementException();
        int index = StdRandom.uniform(1, count + 1);
//        System.out.println(index);
        if (index == 1) {
            return start.data;
        }
        else {
            int j = 1;
            Node itr = start;
            while (j != index) {
                itr = itr.next;
                j++;
            }
            return itr.data;
        }
    }

    @Override
    public Iterator<Item> iterator() {
        return new RandomIterator();
    }

    private class Node {
        Item data;
        Node next = null;
    }

    private class RandomIterator implements Iterator<Item> {

        final private Item[] array = (Item[]) new Object[count];
        int j;
        private int N = count;

        public RandomIterator() {
            Node itr = start;
            j = 0;
            while (itr != null) {
                array[j++] = itr.data;
                itr = itr.next;
            }
            StdRandom.shuffle(array);
        }

        @Override
        public boolean hasNext() {
            return N > 0;
        }

        @Override
        public Item next() {
            if (N == 0)
                throw new NoSuchElementException();
            return array[--N];
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }
}
