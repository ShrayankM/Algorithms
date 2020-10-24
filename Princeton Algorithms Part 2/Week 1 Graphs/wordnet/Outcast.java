import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.In;
public class Outcast {

    private WordNet wn;
    public Outcast(WordNet wordnet)   // constructor takes a WordNet object
    {
        if (wordnet == null) throw new IllegalArgumentException();
        wn = wordnet;
    }

    public String outcast(String[] nouns)   // given an array of WordNet nouns, return an outcast
    {
        if (nouns == null) throw new IllegalArgumentException();
        int maxDist = 0;
        String out = "";
        for (int i = 0; i < nouns.length; i++) {
            int distI = 0;
            for (int j = 0; j < nouns.length; j++) {
                distI += wn.distance(nouns[i], nouns[j]);
            }
            if (maxDist < distI) {
                out = nouns[i];
                maxDist = distI;
            }
        }
        return out;
    }

    public static void main(String[] args) {
        WordNet wordnet = new WordNet(args[0], args[1]);
        Outcast outcast = new Outcast(wordnet);
        for (int t = 2; t < args.length; t++) {
            In in = new In(args[t]);
            String[] nouns = in.readAllStrings();
            StdOut.println(args[t] + ": " + outcast.outcast(nouns));
        }
    }
}