import java.util.Iterator;

public class Main {

    public static void main(String[] args) {
        Indexing<String, String> index = new Indexing<>();

        String [] str = {"today the knight rises" , "the dark knight", "rises the sun everyday",
                         "today the knight rises" };
        for (int i = 0; i < str.length; i++) {
            String [] s = str[i].split(" ");
            for (int j = 0; j < s.length; j++) {
                index.add(s[j], str[i]);
            }
        }

        Set<String> rt = index.get("rises");
        for (Iterator<String> it = rt.iterator(); it.hasNext(); ) {
            String s = it.next();
            System.out.println(s);
        }
    }
}
