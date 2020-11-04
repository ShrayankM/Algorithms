public class Student {

    private int section;
    private String name;
    private int marks;

    Student(int section, String name, int marks) {
        this.section = section;
        this.name = name;
        this.marks = marks;
    }

    public int getSection() {
        return this.section;
    }

    @Override
    public String toString() {
        return ("Section = " + section + " Name : " + name + " Marks = " + marks);
    }
}
