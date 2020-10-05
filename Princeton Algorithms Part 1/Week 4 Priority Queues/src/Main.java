public class Main {

    public static void main(String[] args) {
	// write your code here
        int [] arr = {34, 7, 67, 3, 12, 23, 67, 45, 13, 78, 1, 77, 54};
        MaxHeap heap = new MaxHeap(arr.length);

        for (int i = 0; i < arr.length; i++)
            heap.insert(arr[i]);

        heap.sort();

        heap.display();
//        System.out.println(heap.delete());
//
//        heap.display();
//        System.out.println(heap.delete());
//
//        heap.display();
//        System.out.println(heap.delete());
    }
}
