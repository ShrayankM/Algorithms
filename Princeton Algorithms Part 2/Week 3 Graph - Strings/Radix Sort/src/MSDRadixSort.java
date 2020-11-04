import java.util.Arrays;

public class MSDRadixSort {

    public static int CharAt(String arr, int d) {
        if (d < arr.length()) return arr.charAt(d);
        return -1;
    }

    public static void sort(String [] arr, String [] aux, int lo, int hi, int d) {
        if (hi <= lo) return;

        int R = 256;
        int [] count = new int[R + 1];
        Arrays.fill(count, 0);

        for (int i = lo; i <= hi; i++) count[CharAt(arr[i], d) + 2]++;

        for (int i = 0; i < R; i++) count[i + 1] += count[i];

        for (int i = lo; i <= hi; i++) aux[count[CharAt(arr[i], d) + 1]++] = arr[i];

        for (int i = lo; i <= hi; i++) arr[i] = aux[i - lo];

        for (int r = 0; r < R; r++)
            sort(arr, aux, lo + count[r], lo + count[r + 1] - 1, d + 1);
    }

    public static void main(String [] args) {

        String [] arr = {"abdcx", "acbcklm", "abcd", "aab", "cedxx", "efgklmmn", "cddlmn", "dxlmnr",
                         "dcbbaacd", "dxcd", "ccabbe", "elmnox"};

        int N = arr.length;
        String [] aux = new String[N];

        sort(arr, aux, 0, N - 1, 0);

        for (int i = 0; i < N; i++) System.out.println(arr[i]);
    }
}
