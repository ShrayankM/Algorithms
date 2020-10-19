import com.sun.security.auth.module.KeyStoreLoginModule;

import java.util.Iterator;
import java.util.TreeSet;


public class Set<Key extends Comparable<Key>> {


    private TreeSet<Key> tree;
    private int cnt;

    //Constructor
    Set() {
        tree = new TreeSet<>();
        cnt = 0;
    }

    //add key
    public void add(Key key) {
        if (tree.add(key)) cnt++;
    }

    //check if key present
    boolean contains(Key key) {
        return tree.contains(key);
    }

    //remove key
    public void remove(Key key) {
        if (tree.remove(key)) cnt--;
    }

    //return count of keys in set
    public int size() {
        return cnt;
    }

    //return all the keys in the set
    Iterator<Key> iterator() {
        return tree.iterator();
    }

    public static void main(String[] args) {
        Set<Integer> mySet = new Set<>();

        Integer [] arr = {34, 34, 56, 78, 7, 78, 90, 0, 12, 12, 1};
        for (Integer i : arr) {
            mySet.add(i);
        }

        for (Iterator<Integer> it = mySet.iterator(); it.hasNext(); ) {
            Integer i = it.next();
            System.out.print(i + " ");
        }
        System.out.println();
        System.out.println(mySet.size());

    }
}
