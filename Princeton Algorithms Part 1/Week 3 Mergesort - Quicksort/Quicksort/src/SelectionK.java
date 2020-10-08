public class SelectionK {
    public Comparable select(Comparable [] a, int k) {
        int L = 0, H = a.length - 1;
        while (L < H) {
            int p = partition(a, L, H);
            if (p > k)      H = p - 1;
            else if (p < k) L = p + 1;
            else            return a[k];
        }
        return a[k];
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
