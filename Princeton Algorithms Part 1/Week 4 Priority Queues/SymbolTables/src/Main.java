public class Main {

    public static void main(String[] args) {
	// write your code here
        BinarySearchTree<Integer, Integer> bst = new BinarySearchTree<>();
        Integer [] arr = {54, 67, 12, 56, 23, 78, 10, 6, 34, 67, 99};
        for (int i = 0; i < arr.length; i++) {
            bst.insert(arr[i], i);
        }

        for (Integer i : bst.keys()) {
            System.out.print(i + " ");
        }
        System.out.println();
//        bst.inorder();
        System.out.println("Floor of " + 13 + " " + bst.floor(13));
        System.out.println("Ceil of " + 13 + " " + bst.ceil(13));

        System.out.println(bst.size());
        System.out.println(bst.rank(34));

        bst.delete(54);
        bst.delete(23);
        System.out.println(bst.rank(34));
        for (Integer i : bst.keys()) {
            System.out.print(i + " ");
        }
    }
}
