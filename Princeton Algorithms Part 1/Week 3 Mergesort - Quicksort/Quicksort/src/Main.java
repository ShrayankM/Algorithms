public class Main {

    public static void main(String[] args) {
//        Quicksort q = new Quicksort();
//        int a[] = {12, 6, 23, 6, 7, 11, 9, 3, 45, 32, 16, 8};
//        q.sort(a);
//        q.display(a);

        QuicksortGeneric q = new QuicksortGeneric();
        Integer a[] = {12, 6, 23, 6, 7, 11, 9, 3, 45, 32, 16, 8};
//        Integer a[] = {1, 2, 3, 4, 5, 6, 7};
        q.sort(a);
        q.display(a);

        Float b[] = {1.2F, 3.4F, 12.6F, 78F, 15.66F, 14.66F};
        q.sort(b);
        q.display(b);
    }
}
