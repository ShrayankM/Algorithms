public class LSDRadixInteger {

    public static void sort(String [] arr, int W) {

        int R = 2000;
        int N = arr.length;
        for (int d = W - 1; d >= 0; d--) {
            String [] aux = new String[N + 1];
            int [] count = new int[R + 1];

            for (int i = 0; i < N; i++) count[arr[i].charAt(d) + 1]++;

            for (int i = 0; i < R; i++) count[i + 1] += count[i];

            for (int i = 0; i < N; i++) aux[count[arr[i].charAt(d)]++] = arr[i];

            for (int i = 0; i < N; i++) arr[i] = aux[i];
        }
    }

    public static void main(String [] args) {
        int [] arr = {567, 78, 1, 45, 23, 56, 90, 1045, 1, 2, 22};
        String [] str = new String[arr.length];

        for (int i = 0; i < arr.length; i++) {
            String result = Integer.toBinaryString(arr[i]);
            String resultWithPadding = String.format("%32s", result).replaceAll(" ", "0");
            str[i] = resultWithPadding;
        }

        sort(str, 32);

        for (int i = 0; i < arr.length; i++) {
//            System.out.println(str[i]);
            System.out.println(Integer.parseInt(str[i], 2));
        }
    }
}
