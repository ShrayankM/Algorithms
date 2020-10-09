public class Main {

    public static void main(String[] args) {
	// write your code here
        BinarySearchTree<Integer, Integer> bst = new BinarySearchTree<>();
        Integer [] arr = {54, 67, 12, 56, 23, 78, 10, 6, 34, 67, 99};
        for (int i = 0; i < arr.length; i++) {
            bst.insert(arr[i], i);
        }
        bst.inorder();
    }
}
