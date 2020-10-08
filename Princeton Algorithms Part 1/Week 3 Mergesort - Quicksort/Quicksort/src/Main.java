public class Main {

    public static void display(Comparable [] a) {
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        QuicksortNew q = new QuicksortNew();
        Integer [] a = {34, 56, 9, 12, 78, 23, 78, 9, 10, 10, 45, 10};
        Integer [] b = {34, 56, 9, 12, 78, 23, 78, 9, 10, 10, 45, 10};
        q.sort(a);
        display(a);

        SelectionK s = new SelectionK();
        System.out.println(s.select(b, 4));

        Integer [] c = {34, 56, 9, 12, 78, 23, 78, 9, 5, 7, 45, 10, 10, 56};
        threeWaySort t = new threeWaySort();
        t.sort(c);
        display(c);

    }
}
