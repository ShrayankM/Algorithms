import java.util.Comparator;

public class MergesortObject {

    private boolean less(Object a, Object b, Comparator c) {
        return c.compare(a, b) < 0;
    }

    private void merge(Object arr[], Object aux[], int L, int MID, int H, Comparator c) {
        int i = L, j = MID + 1;
        for (int k = L; k <= H; k++)
            aux[k] = arr[k];

        for (int k = L; k <= H; k++) {
            if (i > MID)                      arr[k] = aux[j++];
            else if (j > H)                   arr[k] = aux[i++];
            else if (less(aux[i], aux[j], c)) arr[k] = aux[i++];
            else                              arr[k] = aux[j++];
        }
    }

    private void sort(Object arr[], Object aux[], int L, int H, Comparator c) {
        if (L < H) {
            int MID = (L + H)/2;
            sort(arr, aux, L, MID, c);
            sort(arr, aux, MID + 1, H, c);
            merge(arr, aux, L, MID, H, c);
        }
    }

    public void sort(Object arr[], Comparator c) {
        Object aux[] = new Object[arr.length];
        sort(arr, aux, 0, arr.length - 1, c);
    }
}
