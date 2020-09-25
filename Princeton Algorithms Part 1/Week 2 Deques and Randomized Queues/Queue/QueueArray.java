import java.util.Iterator;
import java.util.NoSuchElementException;

public class QueueArray<Item> implements Iterable<Item> {
    private Item array[];
    private int head, tail;
    public QueueArray() {
        array = (Item[]) new Object[2];
        head = 0; tail = 0;
    }

    public void enqueue(Item item) {
        array[tail] = item;
        tail = (tail + 1) % array.length;
        if ((tail + 1) % array.length == head) {
            resize(array.length * 2);
        }
    }

    public Item dequeue() {
        if (head == tail)
            throw new NoSuchElementException();
        Item temp = array[head];
        array[head] = null;
        head = (head + 1) % array.length;
        if (head == tail) {
            head = 0; tail = 0;
        }

        if (Math.abs(tail - head) < array.length/4)
            resize(array.length/2);
        return temp;
    }

    private void resize(int size) {
        Item copy[] = (Item[]) new Object[size];
        int j = 0; int i = head;
//        for (int i = head; i < tail; i = (i + 1)% array.length) {
//            copy[j++] = array[i];
//        }
        while(i != tail) {
            copy[j++] = array[i];
            i = (i + 1) % array.length;
        }
        array = copy;
        head = 0; tail = j;
    }

    public static void main(String args[]) {
        QueueArray<Integer> q = new QueueArray<Integer>();

        q.enqueue(100);
        q.enqueue(200);
        q.enqueue(300);

        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
        for (int i = 1; i <= 10; i++) {
            q.enqueue(i * 10);
        }

        for (int i = 1; i <= 10; i++) {
            System.out.println(q.dequeue());
        }

        for (int i = 1; i <= 10; i++) {
            q.enqueue(i * 10 * -1);
        }

        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
//
        for (int i = 1; i <= 10; i++) {
            System.out.println(q.dequeue());
        }
    }

    @Override
    public Iterator<Item> iterator() {
        return null;
    }
}
