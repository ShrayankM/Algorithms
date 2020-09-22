import edu.princeton.cs.algs4.StdIn;

import java.util.Iterator;

public class Permutation {
    public static void main(String[] args) {
        int k = Integer.parseInt(args[0]);
        RandomizedQueue<String> r = new RandomizedQueue<String>();
//        while (!StdIn.isEmpty()) {
//            String str = StdIn.readString();
//            r.enqueue(str);
//        }

        r.enqueue("ab");
        System.out.println(r.dequeue());
//        r.enqueue("cd");
//        r.enqueue("ef");
//        r.enqueue("gh");
//        r.enqueue("ik");

        Iterator<String> itr = r.iterator();
        while (itr.hasNext() && k > 0) {
            k--;
            System.out.println(itr.next());
        }
//        for (String s: r) {
//            System.out.println(s);
//        }
    }
}
