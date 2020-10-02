
public class Quicksort {
    public void sort(int a[]) {
        sort(a, 0, a.length - 1);
    }

    private void sort(int a[], int L, int H) {
        if (L < H) {
            int p = partition(a, L, H);
            sort(a, L, p - 1);
            sort(a, p + 1, H);
        }
    }

    private int partition(int a[], int L, int H) {
        int pivot = a[L];
        int i = L, j = H + 1;

        while (i < j) {
            while (a[++i] <= pivot) {
                if (i == H) break;
            }

            while (a[--j] > pivot) {
                if (j == L) break;
            }

            if (i < j) {
                exchange(a, i, j);
            }
        }
        exchange(a, L, j);
        return j;
    }

    private void exchange(int a[], int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public void display(int a[]) {
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }

}
