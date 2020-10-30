public class KeyIndexCounting {

    public static void sort(char [] arr) {
        int R = 256;
        int N = arr.length;
        int [] count = new int[R + 1];
        char [] aux = new char[N];

        for (char c : arr) count[c - 'a' + 1]++;

        for (int i = 0; i < R; i++) count[i + 1] += count[i];

        for (int i = 0; i < N; i++) aux[count[arr[i] - 'a']++] = arr[i];

        for (int i = 0; i < N; i++) arr[i] = aux[i];
    }

    public static void main(String [] args) {
        char [] arr = {'a', 'b', 'g', 'b', 'c', 'a', 'b', 'e', 'e', 'g', 'c'};

        sort(arr);
        for (char c : arr) System.out.print(c + " ");
        System.out.println();
    }
}
