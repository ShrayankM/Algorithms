public class threeWaySort {

    private void sort(Comparable [] a, int L, int H) {
        if (L >= H) return;
        int LT = L, GT = H;
        Comparable v = a[L];

        int i = LT;
        while (i <= GT) {
            int cmp = a[i].compareTo(v);
            if (cmp < 0)      exchange(a, LT++, i++);
            else if (cmp > 0) exchange(a, i, GT--);
            else              i++;
        }

        sort(a, L, LT - 1);
        sort(a, GT + 1, H);
    }

    private void exchange(Comparable [] a, int i, int j) {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    public void sort(Comparable [] a) {
        sort(a, 0, a.length - 1);
    }
}
