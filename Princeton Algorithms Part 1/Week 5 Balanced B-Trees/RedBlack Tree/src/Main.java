public class Main {

    public static void main(String[] args) {
	// write your code here
        Integer [] arr = {12, 34, 5, 67, 38, 21, 78, 45, 56, 44};
        RedBlackTree<Integer, Integer> rb = new RedBlackTree<>();

        for (int i = 0; i < arr.length; i++) {
            rb.insert(arr[i], i);
        }

        for (Integer n : rb.keys())
            System.out.print(n + " ");
        System.out.println();
    }
}
