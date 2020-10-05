public class Heapsort {

    public void createHeap(Comparable[] a) {
        for (int i = a.length - 1; i >= 1; i--) {
            checkHeap(a, i);
        }
    }

    private void checkHeap(Comparable[] a, int index) {
        while (index/2 >= 1 && less(a[index/2], a[index])) {
            exchange(a, index/2, index);
            index = index/2;
        }
    }

    private void exchange(Comparable[] a, int i, int j) {
        Comparable t = a[j];
        a[j] = a[i];
        a[i] = t;
    }

    private void sort(Comparable [] a) {
        int size = a.length;
        while (size > 1) {
            exchange(a, 1, size - 1);
            heapify(a, 1, --size);
        }
    }

    private void heapify(Comparable [] a, int index, int size) {
        int parent = index;
        int indexL = 2 * index, indexR = 2 * index + 1;
        if (indexL < size && less(a[index], a[indexL])) index = indexL;
        if (indexR < size && less(a[index], a[indexR])) index = indexR;

        if (parent != index) {
            exchange(a, parent, index);
            heapify(a, index, size);
        }
    }

    public static void display(Comparable [] arr) {
        for (int i = 1; i < arr.length; i++)
            System.out.print(arr[i] + " ");
        System.out.println();

    }

    private boolean less(Comparable a, Comparable b) {
        return a.compareTo(b) < 0;
    }

    public static void main(String[] args) {
        Integer [] arr = {0, 12, 5, 6, 23, 67, 8};
        Double [] arr2 = {0.0, 0.7, 12.66, 5.67, 6.01, 23.56, 67.78, 8.88, 8.889, 8.08};

        Heapsort heap = new Heapsort();
        heap.createHeap(arr);


        display(arr);
        heap.sort(arr);
        display(arr);

        heap.createHeap(arr2);
        display(arr2);
        heap.sort(arr2);
        display(arr2);

    }
}
