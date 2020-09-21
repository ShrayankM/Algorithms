import java.util.Iterator;

public class ArrayStack<Item> implements Iterable<Item> {
    private Item [] array;
    private int N;

    public ArrayStack() {
        array = (Item[]) new Object[1];
        N = 0;
    }

    public void push(Item item) {
        if (N == array.length)
            resize(N * 2);
        array[N++] = item;
    }

    public Item pop() {
        if (N > 0 && N == array.length/4)
            resize(array.length/2);
        return array[--N];
    }

    private void resize(int size) {
        Item copy[] = (Item[]) new Object[size];
        for (int i = 0; i < N; i++) {
            copy[i] = array[i];
        }
        array = copy;
    }

    private class StackIterator implements Iterator<Item> {

        private int i = N;
        @Override
        public boolean hasNext() {
            return i > 0;
        }

        @Override
        public Item next() {
            return array[--i];
        }
    }
    @Override
    public Iterator<Item> iterator() {
        return new StackIterator();
    }

    public static void main(String args[]) {
        ArrayStack<Integer> stack = new ArrayStack<Integer>();
        for (int i = 1; i <= 10; i++) {
            stack.push(i * 10);
        }

        for (int key : stack) {
            System.out.println(key);
        }
    }
}
