public class MaxHeap {
    private int [] array;
    private int size;

    MaxHeap(int heapL) {
        array = new int[heapL + 1];
        size = 1;
    }

    public void insert(int key) {
        if (size == array.length) {
            resize(size * 2);
        }
        array[size++] = key;
        checkHeap(size - 1);
    }

    public int delete() {
        exchange(1, size - 1);
        int t = array[--size];
        heapify(1);
        return t;
    }

    public void sort() {
        int sizeL = size;
        while (size > 1) {
            delete();
        }

        for (int i = 1; i < sizeL; i++)
            System.out.print(array[i] + " ");
        System.out.println();

        for (int i = 1; i < sizeL; i++) {
            insert(array[i]);
        }
    }

    private void heapify(int index) {
        int parent = index;
        int indexL = 2 * index, indexR = 2 * index + 1;
        if (indexL < size && less(array[index], array[indexL])) index = indexL;
        if (indexR < size && less(array[index], array[indexR])) index = indexR;

        if (parent != index) {
            exchange(parent, index);
            heapify(index);
        }
    }

    private void checkHeap(int index) {
        while (index/2 >= 1 && less(array[index/2], array[index])) {
            exchange(index/2, index);
            index = index/2;
        }
    }

    private void exchange(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    private boolean less(int a, int b) {
        if (a  <  b) return true;
        return false;
    }

    private void resize(int size) {
        int [] temp = new int[size];
        System.arraycopy(array, 1, temp, 1, array.length);
//        for (int i = 0; i < array.length; i++) {
//            temp[i] = array[i];
//        }
        array = temp;
    }

    public void display() {
        for (int i = 1; i < this.size; i++)
            System.out.print(array[i] + " ");
        System.out.println();
    }

}
