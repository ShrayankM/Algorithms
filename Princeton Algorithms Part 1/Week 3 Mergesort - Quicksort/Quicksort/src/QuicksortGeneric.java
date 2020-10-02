public class QuicksortGeneric {
    public void sort(Comparable a[]) {
        sort(a, 0, a.length - 1);
    }

    private void sort(Comparable a[], int L, int H) {
        if (L < H) {
            int p = partition(a, L, H);
            sort(a, L, p - 1);
            sort(a, p + 1, H);
        }
    }

    private boolean less(Comparable a, Comparable b) {
        return a.compareTo(b) < 0;
    }

    private void exchange(Comparable a[], int i, int j) {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    public void display(Comparable a[]) {
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }

    private int partition(Comparable a[], int L, int H) {
        Comparable pivot = a[L];
        int i = L, j = H + 1;

        while (i < j) {
            while (less(a[++i], pivot)) {
                if (i == H) break;
            }

            while (less(pivot, a[--j])) {
                if (j == L) break;
            }

            if (i < j) {
                exchange(a, i, j);
            }
        }
        exchange(a, L, j);
        return j;
    }
}
