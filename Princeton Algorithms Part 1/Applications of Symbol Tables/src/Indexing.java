import java.util.TreeMap;

public class Indexing<Key extends Comparable<Key>, Value extends Comparable<Value>> {
    private TreeMap<Key, Set<Value>> tree;

    //Constructor
    Indexing() {
        tree = new TreeMap<>();
    }

    //add new key, value pair
    public void add(Key key, Value value) {
        if (tree.containsKey(key)) {
            Set<Value> st = tree.get(key);
            st.add(value);
            tree.put(key, st);
        }
        else {
            Set<Value> st = new Set<>();
            st.add(value);
            tree.put(key, st);
        }
    }

    //get value
    public Set<Value> get(Key key) {
        return tree.get(key);
    }
}
