import java.util.Comparator;

public class Student {

    private String name;
    private int id;
    private int marks;

    public Student(String name, int id, int marks) {
        this.name = name;
        this.id = id;
        this.marks = marks;
    }

    private static final Comparator<Student> StudentMarks = new StudentMarks();
    private static final Comparator<Student> StudentId = new StudentId();

    private static class StudentMarks implements Comparator<Student> {

        @Override
        public int compare(Student s1, Student s2) {
            if (s1.marks <= s2.marks) return 1;
            else                      return 0;
        }
    }

    private static class StudentId implements Comparator<Student> {

        @Override
        public int compare(Student s1, Student s2) {
            if (s1.id <= s2.id) return 1;
            else                      return 0;
        }
    }

    private static boolean less(Object a, Object b, Comparator StudentMarks) {
        return StudentMarks.compare(a, b) > 0;
    }

    private static void merge(Object a[], Object aux[], int L, int MID, int H, Comparator StudentMarks) {

        for (int i = L; i <= H; i++)
            aux[i] = a[i];

        int i = L, j = MID + 1;

        for (int k = L; k <= H; k++) {
            if (i > MID)                   { a[k] = aux[j++]; }
            else if (j > H)                { a[k] = aux[i++]; }
            else if (less(aux[i], aux[j], StudentMarks)) { a[k] = aux[i++]; }
            else                           { a[k] = aux[j++]; }
        }
    }

    private static void sort(Object a[], Object aux[], int L, int H, Comparator StudentMarks) {
        if (L < H) {
            int MID = (L + H)/2;
            sort(a, aux, L, MID, StudentMarks);
            sort(a, aux, MID + 1, H, StudentMarks);
            merge(a, aux, L, MID, H, StudentMarks);
        }
    }

    public static void sort(Object a[], int type) {
        Object aux[] = new Object[a.length + 1];
        if (type == 0)
            sort(a, aux, 0, a.length - 1, StudentMarks);
        else if (type == 1)
            sort(a, aux, 0, a.length - 1, StudentId);
    }

    public static void show(Student s) {
        System.out.println("Name:" + s.name + " Marks:" + s.marks);
    }

    public static void display(Student arr[]) {
        for (int i = 0; i < arr.length; i++)
            show(arr[i]);
    }

    public static void main(String args[]) {
        Student s1 = new Student("Jack", 1, 89);
        Student s2 = new Student("Robin", 2, 56);
        Student s3 = new Student("Robert", 3, 94);
        Student s4 = new Student("Tony", 4, 67);

        Student arr[] = {s1, s2, s3, s4};
        sort(arr, 0);
        display(arr);

        System.out.println();
        sort(arr, 1);
        display(arr);
    }
}
