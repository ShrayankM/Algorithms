import java.util.Iterator;
import java.util.TreeMap;

public class Dictionary<Key extends Comparable<Key>, Value> {
    private TreeMap<Key, Value> tree;
    private int cnt;

    //Constructor
    Dictionary() {
        tree = new TreeMap<>();
        cnt = 0;
    }

    //add key
    public void add(Key key, Value value) {
        if (!contains(key)) {
            tree.put(key, value);
            cnt++;
        }
    }

    //get value
    public Value get(Key key) {

        if (tree.get(key) == null) return (Value) "NOt Found";
        return tree.get(key);
    }

    //check if key present
    boolean contains(Key key) {
        return tree.containsKey(key);
    }

    //remove key
    public void remove(Key key) {
        tree.remove(key);
    }

    //return count of keys in set
    public int size() {
        return cnt;
    }

    //return all the keys in the set
    public Iterator<Key> keys() {
        return tree.keySet().iterator();
    }

    //return all the values in the set
    public Iterator<Value> values() {
        return tree.values().iterator();
    }

    public static void main(String[] args) {
        Dictionary<String, String> urlMap = new Dictionary<>();

        String [] url = {"www.google.com", "www.wikipedia.com", "www.yahoo.com", "www.github.com",
                "www.github.com"};
        String [] ip  = {"123.90.5.45",     "145.145.67.99",     "100.7.0.89",    "128.78.0.0",
                "0.0.0.0"};

        for (int i = 0; i < url.length; i++) {
            urlMap.add(url[i], ip[i]);
        }

        //Print all the urls present
        System.out.println("----------------URLS---------------");
        for (Iterator<String> it = urlMap.keys(); it.hasNext(); ) {
            String u = it.next();
            System.out.println(u);
        }
        System.out.println("-----------------------------------");

        System.out.println();

        System.out.println("----------------IPS---------------");
        for (Iterator<String> it = urlMap.values(); it.hasNext(); ) {
            String i = it.next();
            System.out.println(i);
        }
        System.out.println("-----------------------------------");

        System.out.println();

        //Print all the urls and the ips present
        System.out.println("----------------URLS/IPS---------------");
        for (Iterator<String> it = urlMap.keys(); it.hasNext(); ) {
            String u = it.next();
            String i = urlMap.get(u);
            System.out.println(u + " --> " + i);
        }
        System.out.println("-----------------------------------");

        String i = urlMap.get("www.facebook.com");
        System.out.println(i);
    }
}
