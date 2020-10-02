import java.util.Comparator;

public class QuicksortObject {
    public void sort(Object a[], Comparator c) {
        sort(a, 0, a.length - 1, c);
    }

    private void sort(Object a[], int L, int H, Comparator c) {
        if (L < H) {
            int p = partition(a, L, H, c);
            sort(a, L, p - 1, c);
            sort(a, p + 1, H, c);
        }
    }

    private boolean less(Object a, Object b, Comparator c) {
        return c.compare(a, b) < 0;
    }

    private void exchange(Object a[], int i, int j) {
        Object t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    private int partition(Object a[], int L, int H, Comparator c) {
        Object pivot = a[L];
        int i = L, j = H + 1;

        while (i < j) {
            while (less(a[++i], pivot, c)) {
                if (i == H) break;
            }

            while (less(pivot, a[--j], c)) {
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
