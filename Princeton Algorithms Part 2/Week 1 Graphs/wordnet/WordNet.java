import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.StdIn;

import java.util.Iterator;
import java.util.TreeMap;
import java.util.TreeSet;

public class WordNet {

    private TreeMap<Integer, String> nounMap;
    private TreeSet<String> nouns;
    private Digraph G;
    private SAP sp;

    // constructor takes the name of the two input files
    public WordNet(String synsets, String hypernyms) {
        if (synsets == null || hypernyms == null) throw new IllegalArgumentException();
        nounMap = new TreeMap<>();
        nouns = new TreeSet<>();
        In s = new In(synsets);

        while (!s.isEmpty()) {
            String [] str = s.readLine().split(",");
            int id = Integer.parseInt(str[0]);
            String noun = str[1];
            nounMap.put(id, noun);

            String [] nounsStr = noun.split(" ");
            for (int i = 0; i < nounsStr.length; i++)
                nouns.add(nounsStr[i]);
        }

        G = new Digraph(nounMap.size());
        In h = new In(hypernyms);

        while (!h.isEmpty()) {
            String [] str = h.readLine().split(",");
            int v = Integer.parseInt(str[0]);

            for (int j = 1; j < str.length; j++) {
                int w = Integer.parseInt(str[j]);
                G.addEdge(v, w);
            }
        }
        sp = new SAP(G);

        // Topological tp = new Topological(G);
        CycleDetection cycle = new CycleDetection(G);
        if (cycle.graphHasCycle()) throw new IllegalArgumentException();
        if (checkGraph(G)) throw new IllegalArgumentException();
    }

    private boolean checkGraph(Digraph G) {
        int cnt = 0;
        for (int i = 0; i < G.V(); i++) {
            if (G.outdegree(i) == 0) {
                cnt++;
            }
        }
        if (cnt > 1) return true;
        return false;
    }

    // returns all WordNet nouns
    public Iterable<String> nouns() {
        Queue<String> rt = new Queue<>();
        Iterator<String> itr = nouns.iterator();
        while (itr.hasNext()) {
            rt.enqueue(itr.next());
        }
        return rt;
    }

    // is the word a WordNet noun?
    public boolean isNoun(String word) {
        if (word == null) throw new IllegalArgumentException();
        return nouns.contains(word);
    }

    // distance between nounA and nounB (defined below)
    public int distance(String nounA, String nounB) {
        if (nounA == null || nounB == null) throw new IllegalArgumentException();
        if (!isNoun(nounA) || !isNoun(nounB)) throw new IllegalArgumentException();

        Queue<Integer> a = new Queue<>();
        Queue<Integer> b = new Queue<>();

        for (int id : nounMap.keySet()) {
            String value = nounMap.get(id);
            String [] str = value.split(" ");

            if (value.contains(nounA)) {
                for (int i = 0; i < str.length; i++) {
                    if (str[i].compareTo(nounA) == 0) {
                        a.enqueue(id);
                        break;
                    }
                }
            }

            if (value.contains(nounB)) {
                for (int i = 0; i < str.length; i++) {
                    if (str[i].compareTo(nounB) == 0) {
                        b.enqueue(id);
                        break;
                    }
                }
            }
            // if (value.contains(nounA)) a.enqueue(id);
            // if (value.contains(nounB)) b.enqueue(id);
        }

        // SAP sp = new SAP(G);
        return sp.length(a, b);
    }

    // a synset (second field of synsets.txt) that is the common ancestor of nounA and nounB
    // in a shortest ancestral path (defined below)
    public String sap(String nounA, String nounB) {
        if (nounA == null || nounB == null) throw new IllegalArgumentException();
        if (!isNoun(nounA) || !isNoun(nounB)) throw new IllegalArgumentException();

        Queue<Integer> a = new Queue<>();
        Queue<Integer> b = new Queue<>();

        for (int id : nounMap.keySet()) {
            String value = nounMap.get(id);
            String [] str = value.split(" ");

            if (value.contains(nounA)) {
                for (int i = 0; i < str.length; i++) {
                    if (str[i].compareTo(nounA) == 0) {
                        a.enqueue(id);
                        break;
                    }
                }
            }

            if (value.contains(nounB)) {
                for (int i = 0; i < str.length; i++) {
                    if (str[i].compareTo(nounB) == 0) {
                        b.enqueue(id);
                        break;
                    }
                }
            }
            // if (value.contains(nounA)) a.enqueue(id);
            // if (value.contains(nounB)) b.enqueue(id);
        }

        // viewGroup(nounA, a);
        // viewGroup(nounB, b);

        // SAP sp = new SAP(G);
        int ancestor = sp.ancestor(a, b);
        return nounMap.get(ancestor);
    }

    private void viewGroup(String str, Queue<Integer> q) {
        System.out.print("Group " + str + " [");
        for (int members : q) {
            System.out.print(nounMap.get(members) + " ");
        }
        System.out.print("]\n");
    }

    // do unit testing of this class
    public static void main(String[] args) {
        String a = args[0];
        String b = args[1];

        WordNet wn = new WordNet(a, b);

        while (!StdIn.isEmpty()) {
            String v = StdIn.readString();
            String w = StdIn.readString();

            System.out.println("Ancestor of (" + v + ", " + w + ") = " + wn.sap(v, w));
            System.out.println("Length   of (" + v + ", " + w + ") = " + wn.distance(v, w));
        }
    }
}