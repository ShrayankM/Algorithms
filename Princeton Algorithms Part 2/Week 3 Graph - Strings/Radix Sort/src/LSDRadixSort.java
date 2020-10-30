public class LSDRadixSort {

    public static void sort(String [] arr, int W) {

        int R = 256;
        int N = arr.length;

//        for (int i = 0; i < N; i++) aux[i] = arr[i];

        for (int d = W - 1; d >= 0; d--) {
            String [] aux = new String[N + 1];
            int [] count = new int[R + 1];

            for (int i = 0; i < N; i++) count[arr[i].charAt(d) - 'a' + 1]++;

            for (int i = 0; i < R; i++) count[i + 1] += count[i];

            for (int i = 0; i < N; i++) aux[count[arr[i].charAt(d) - 'a']++] = arr[i];

            for (int i = 0; i < N; i++) arr[i] = aux[i];
        }
    }

    public static void main(String [] args) {
        String [] arr = {"acb", "ecd", "abc", "acc", "bde", "bee", "cde", "bde", "baa"};
        int W = arr[0].length();

        sort(arr, W);

        for(String str : arr) System.out.print(str + " ");
        System.out.println();
    }
}
