public class Client {
    public static void main(String[] args) {
        Deque<Integer> d = new Deque<Integer>();
        for (int i = 1; i <= 1; i++) {
            d.addFirst(i * 10);
        }
        System.out.println(d.removeFirst());
        for (int i = 1; i <= 1; i++) {
            d.addFirst(i * 10);
        }
        System.out.println(d.removeLast());
    }
}
