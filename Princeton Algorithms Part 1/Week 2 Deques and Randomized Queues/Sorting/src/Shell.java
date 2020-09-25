public class Shell {
    public static void sort(Comparable [] array, int step) {
        for (int i = step; i < array.length; i++) {
            for (int j = i; (j >= step); j = j - step) {
                if (less(array[j], array[j - step]))
                    exchange(array, j, j - step);
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
        int h = 1;
        while (h < array.length/3)
            h = 3 * h + 1;

        while (h >= 1) {
            sort(array, h);
            show(array);
            h = h/3;
        }
        show(array);
    }
}
