public class QuicksortNew {
    public void sort(Comparable[] a) {
        quicksort(a, 0, a.length - 1);
    }

    private void quicksort(Comparable [] a,int L, int H) {
        if (L < H) {
            int p = partition(a, L, H);
            quicksort(a, L, p - 1);
            quicksort(a, p + 1, H);
        }
    }

    private int partition(Comparable [] a, int L, int H) {
        int pivot = L;
        int i = L, j = H + 1;

        while (i < j) {
            do {
                i++;
                if (i == H) break;
            } while(less(a[i], a[pivot]));

            do {
                j--;
                if (j == L) break;
            } while(less(a[pivot], a[j]));

            if (i < j)
                exchange(a, i, j);
        }
        exchange(a, pivot, j);
        return j;
    }

    private void exchange(Comparable [] a, int i, int j) {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    private boolean less(Comparable a, Comparable b) {
        return a.compareTo(b) < 0;
    }
}
