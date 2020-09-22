import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class RandomizedQueue<Item> implements Iterable<Item> {

    private Item [] array;
    private int N;

    public RandomizedQueue() {
        array = (Item[]) new Object[1];
        N = 0;
    }

    public void enqueue(Item item) {
        if (item == null)
            throw new IllegalArgumentException();
        if (N == array.length)
            resize(N * 2);
        array[N++] = item;
    }

    public Item dequeue() {
        if (N == 0)
            throw new NoSuchElementException();
        if (N > 0 && N == array.length/4)
            resize(array.length/2);
        int index = StdRandom.uniform(N);
        Item temp = array[index];
        array[index] = array[N - 1];
        array[N - 1] = temp;
        Item r = array[N - 1];
        array[N - 1] = null;
        N--;
        return r;
    }

    public Item sample() {
        if (N == 0)
            throw new NoSuchElementException();
        int index = StdRandom.uniform(N);
        return array[index];
    }

    private void resize(int size) {
        Item [] copy = (Item[]) new Object[size];
        for (int i = 0; i < N; i++) {
            copy[i] = array[i];
        }
        array = copy;
    }

    public boolean isEmpty() {
        if (N == 0)
            return true;
        return false;
    }

    public int size(){
        return N;
    }
    @Override
    public Iterator<Item> iterator() {
        return new RandomIterator();
    }

    private class RandomIterator implements Iterator<Item> {

        final private Item[] randomArray = (Item[]) new Object[N];
        private int i = N;
        public RandomIterator() {
            for (int i = 0; i < N; i++) {
                randomArray[i] = array[i];
            }
            StdRandom.shuffle(randomArray);
        }

        @Override
        public boolean hasNext() {
            return i > 0;
        }

        @Override
        public Item next() {
            if (i == 0)
                throw new NoSuchElementException();
            return randomArray[--i];
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    public static void main(String args[]) {
        //no body
    }
}
