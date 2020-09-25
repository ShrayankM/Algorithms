public class Student implements Comparable<Student> {
    private int id;
    private String name;
    private int marks;

    public Student(int i, String n, int m) {
        id = i; name = n; marks = m;
    }

    public static void sort(Student[] array) {
        for (int i = 1; i < array.length; i++) {
            int j = i - 1;
            Student key = array[i];
            while(j >= 0 && less(key, array[j])) {
                exchange(array, j, j + 1);
                j--;
            }
            array[j + 1] = key;
        }
    }

    private static void exchange(Student[] array, int j, int i) {
        Student t = array[j];
        array[j] = array[i];
        array[i] = t;
    }

    private static boolean less(Student v, Student w) {
        return v.compareTo(w) < 0;
    }

    @Override
    public int compareTo(Student student) {
        if (this.marks < student.marks) return -1;
        if (this.marks > student.marks) return +1;
        return 0;
    }

    public static void show(Student array[]) {
        for (int i = 0; i < array.length; i++)
            System.out.println(array[i].name + " " + array[i].marks);
    }

    public static void main(String args[]) {
        Student S1 = new Student(1, "Jack", 87);
        Student S2 = new Student(2, "Robin", 76);
        Student S3 = new Student(3, "Russell", 65);
        Student S4 = new Student(4, "Lando", 92);
        Student S5 = new Student(5, "Robert", 56);

        Student array[] = {S1, S2, S3, S4, S5};
        sort(array);
        show(array);
    }
}
