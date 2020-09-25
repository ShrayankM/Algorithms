public class Selection {
    public static void sort(Comparable[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            int k = i;
            for (int j = i + 1; j < a.length; j++) {
                if (less(a[j], a[k]))
                    k = j;
            }
            exchange(a, k, i);
        }
    }

    public static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }

    public static void exchange(Comparable [] a, int i, int j) {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    public static void show(Comparable[] a) {
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        Integer array[] = {10, 4, 4, 12, 6, 7, 2, 34, 17, 8};
        sort(array);
        show(array);
    }
}
