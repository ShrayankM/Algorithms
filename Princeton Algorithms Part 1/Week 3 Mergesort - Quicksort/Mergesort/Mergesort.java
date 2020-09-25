public class Mergesort {

    private boolean less(Comparable a, Comparable b) {
        return a.compareTo(b) < 0;
    }

    private void merge(Comparable a[], Comparable aux[], int L, int MID, int H) {

        for (int i = L; i <= H; i++)
            aux[i] = a[i];

        int i = L, j = MID + 1;

        for (int k = L; k <= H; k++) {
            if (i > MID)                   { a[k] = aux[j++]; }
            else if (j > H)                { a[k] = aux[i++]; }
            else if (less(aux[i], aux[j])) { a[k] = aux[i++]; }
            else                           { a[k] = aux[j++]; }
        }
    }

    private void sort(Comparable a[], Comparable aux[], int L, int H) {
        if (L < H) {
            int MID = (L + H)/2;
            sort(a, aux, L, MID);
            sort(a, aux, MID + 1, H);
            merge(a, aux, L, MID, H);
        }
    }

    public void sort(Comparable a[]) {
        Comparable aux[] = new Comparable[a.length + 1];
        sort(a, aux, 0, a.length - 1);
    }
}
