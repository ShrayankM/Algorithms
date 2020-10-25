import java.util.Comparator;
import java.util.Iterator;

public class MinPQ<Item> implements Iterable<Item> {

    private Item [] keys;
    private int index = 1;
    MinPQ() {
        keys = (Item[]) new Object[1];
    }

    public void insert(Item value) {
        if (index == keys.length) resize(keys.length * 2);
        keys[index++] = value;
        swim(index - 1, value);
    }

    public Item delMin() {
        Item t = keys[1];
        exchange(index - 1, 1);
        index--;
        heapify(1, index);
        if ((index > 0) && (index == (keys.length - 1) / 4)) resize(keys.length / 2);
        return t;
    }

    private void heapify(int parent, int n) {
        int i = parent;
        int lChild = 2 * parent, rChild = 2 * parent + 1;

        if (lChild < n && less(keys[lChild], keys[parent])) parent = lChild;
        if (rChild < n && less(keys[rChild], keys[parent])) parent = rChild;

        if (parent != i) {
            exchange(parent, i);
            heapify(parent, n);
        }

    }

    public boolean isEmpty() {
        return index == 1;
    }

    private void swim(int k, Item value) {
        while (k > 1 && less(value, keys[k/2])) {
            exchange(k/2, k);
            k = k/2;
        }
    }

    private boolean less(Item a, Item b) {
        return ((Comparable<Item>) a).compareTo(b) < 0;
    }

    private void exchange(int i, int j) {
        Item temp = keys[i];
        keys[i] = keys[j];
        keys[j] = temp;
    }

    private void resize(int size) {
        Item [] temp = (Item[]) new Object[size];
        for (int i = 0; i < index; i++) temp[i] = keys[i];
        keys = temp;
    }

    private class MinPQIterator implements Iterator<Item> {

        int i = 1;
        @Override
        public boolean hasNext() {
            return i != index;
        }

        @Override
        public Item next() {
            Item t = keys[i];
            i++;
            return t;
        }
    }

    @Override
    public Iterator<Item> iterator() {
        return new MinPQIterator();
    }
}
