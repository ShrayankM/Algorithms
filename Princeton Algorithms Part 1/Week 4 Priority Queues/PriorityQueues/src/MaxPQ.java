public class MaxPQ<Key extends Comparable<Key>> {
    private Key[] array;
    private int size = 1;
    //create empty priority queue
    MaxPQ() {

    }

    //create priority queue with the given keys
    MaxPQ(Key[] a) {
        array = (Key[]) new Comparable[a.length + 1];
        for (int i = 0; i < a.length; i++)
            insert(a[i]);
    }

    //insert new key into priority queue
    void insert(Key v) {
        array[size++] = v;
        checkHeap(size - 1);
    }

    private void checkHeap(int index) {
        while (index/2 >= 1 && less(array[index/2], array[index])) {
            exchange(index/2, index);
            index = index/2;
        }
    }

    private void exchange(int i, int j) {
        Key temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    private boolean less(Key a, Key b) {
        return a.compareTo(b) < 0;
    }

    //return and remove the largest key
    Key delMax() {
        exchange(1, size - 1);
        Key rt = array[--size];
        heapify(1);
        return rt;
    }

    private void heapify(int index) {
        int parent = index;
        int indexL = 2 * index, indexR = 2 * index + 1;

        if (indexL < size && less(array[index], array[indexL])) index = indexL;
        if (indexR < size && less(array[index], array[indexR])) index = indexR;

        if (parent != index) {
            exchange(parent, index);
            heapify(index);
        }
    }

    //is the priority queue empty
    boolean isEmpty() {
        return size == 0;
    }

    //return the largest key
    Key max() {
        return array[1];
    }

    //number of entries in the priority queue
    int size() {
        return size;
    }

    //displays the heap
    public void display() {
        for (int i = 1; i < size; i++)
            System.out.println(array[i]);
        System.out.println();
    }
}
