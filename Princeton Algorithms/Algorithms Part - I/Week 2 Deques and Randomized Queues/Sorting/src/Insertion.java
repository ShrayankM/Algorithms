public class Insertion {
    public static void sort(Comparable [] array) {
        for (int i = 1; i < array.length; i++) {
            for (int j = i; j > 0; j--) {
                if (less(array[j], array[j - 1]))
                    exchange(array, j - 1, j);
                else
                    break;
            }
        }
    }

    private static void exchange(Comparable[] array, int j, int i) {
        Comparable t = array[j];
        array[j] = array[i];
        array[i] = t;
    }

    private static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }

    public static void show(Comparable[] a) {
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        Integer array[] = {10, 4, 4, 12, 6, 7, 2, 34, 4, 17, 8};
        sort(array);
        show(array);
    }
}
