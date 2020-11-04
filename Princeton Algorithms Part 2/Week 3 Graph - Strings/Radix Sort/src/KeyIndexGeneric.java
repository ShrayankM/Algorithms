import edu.princeton.cs.algs4.In;

import java.util.Arrays;

public class KeyIndexGeneric {

    public static void sort(Student [] stu) {

        for (int i = 0; i < stu.length; i++) System.out.println(stu[i]);
        int R = 20;
        int [] count = new int[R + 1];
        Student [] aux = new Student[stu.length];

        Arrays.fill(count, 0);

        for (int i = 0; i < stu.length; i++) count[stu[i].getSection() + 1]++;

        for (int i = 0; i < R; i++) count[i + 1] += count[i];

        for (int i = 0; i < stu.length; i++) aux[count[stu[i].getSection()]++] = stu[i];

        for (int i = 0; i < stu.length; i++) stu[i] = aux[i];
    }

    public static void main(String [] args) {
        Student [] stu = new Student[10];

        String filename = args[0];
        In in = new In(filename);

        int j = 0;
        while(!in.isEmpty()) {
            String [] data = in.readLine().split(" ");
            Student s = new Student(Integer.parseInt(data[0]), data[1], Integer.parseInt(data[2]));
            stu[j] = s;
            j++;
        }

        sort(stu);
        System.out.println("Sorted");
        for (int i = 0; i < j; i++) System.out.println(stu[i]);
    }
}
