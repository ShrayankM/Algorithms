public class Date implements Comparable<Date> {

    private int month, year, day;
    public Date(int m, int y, int d) {
        month = m; year = y; day = d;
    }
    @Override
    public int compareTo(Date date) {
        if (this.year < date.year) return -1;
        if (this.year > date.year) return +1;
        if (this.month < date.month) return -1;
        if (this.month > date.month) return +1;
        if (this.day < date.day) return -1;
        if (this.day > date.day) return +1;
        return 0;
    }


    public static void main(String args[]) {
        Date d1 = new Date(7, 1997, 22);
        Date d2 = new Date(7, 1997, 23);


        if (d1.compareTo(d2) < 0)
            System.out.println("d1 is before d2");
        else if (d1.compareTo(d2) > 0)
            System.out.println("d2 is before d1");
        else
            System.out.println("d2 is the same as d1");
    }
}
