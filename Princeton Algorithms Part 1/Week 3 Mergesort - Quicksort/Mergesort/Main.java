public class Main {

    public static void display(Comparable a[]) {
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }

    public static void main(String[] args) {
	    Mergesort s = new Mergesort();
	    Integer array[] = {12, 4, 5, 17, 15, 6, 23, 45, 1, 2, 34, 2, 2, 6};
	    s.sort(array);
        display(array);

	    Double arr[] = {12.6, 12.3, 5.9, 5.8, 5.11, 5.12,  66.7, 7.44};
        s.sort(arr);
        display(arr);
    }
}
