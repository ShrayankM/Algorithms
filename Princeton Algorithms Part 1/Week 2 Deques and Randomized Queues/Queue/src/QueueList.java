import java.util.Iterator;
import java.util.NoSuchElementException;

public class QueueList<Item> implements Iterable<Item> {

    private Node first = null, last = null;

    private class Node {
        Item data;
        Node next = null;

        Node(Item item) {
            data = item;
        }
    }

    public void enqueue(Item item) {
        Node n = new Node(item);
        if (first == null && last == null) {
            first = n;
        }
        else {
            last.next = n;
        }
        last = n;
    }

    public Item dequeue() {
        if (first == null)
            throw new NoSuchElementException();
        Node n = first;
        first = first.next;
        if(first == null) {
            first = null; last = null;
        }
        return n.data;
    }

    public static void main(String args[]) {
        QueueList<Integer> q = new QueueList<Integer>();
        try{
            q.dequeue();
        }
        catch(NoSuchElementException e) {
            System.out.println("No such element found!!!");
            System.out.println(e);
        }
        q.enqueue(10);

        q.enqueue(20);q.enqueue(30);q.enqueue(40);

        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
    }

    @Override
    public Iterator<Item> iterator() {
        return null;
    }
}
