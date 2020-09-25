import java.util.Collections;
import java.util.Comparator;

public class Movie implements Comparable<Movie> {
    public String name;
    public double rating, budget;
    public int profit;

    public Movie(String name, double rating, double budget, int profit) {
        this.name = name;
        this.rating = rating;
        this.budget = budget;
        this.profit = profit;
    }

    @Override
    public int compareTo(Movie movie) {
        if (this.rating < movie.rating)      return -1;
        else if (this.rating > movie.rating) return 1;
        else                                 return 0;
    }

    public static void display(Movie arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.println("Name:" + arr[i].name + " Rating:" + arr[i].rating);
        }
    }

    public static void main(String args []) {
        Movie m1 = new Movie("M1", 7.5, 6000, 7000);
        Movie m2 = new Movie("M2", 8.7, 2000, 10000);
        Movie m3 = new Movie("M3", 9.5, 10000, 7000);
        Movie m4 = new Movie("M4", 6.5, 5000, 5000);
        Movie m5 = new Movie("M5", 8.2, 11000, 22000);

        Movie array[] = {m1, m2, m3, m4, m5};

//        Mergesort m = new Mergesort();
//        m.sort(array);
//        display(array);

        RatingCompare rating = new RatingCompare();
        MergesortObject m = new MergesortObject();
        m.sort(array, rating);
        display(array);

        System.out.println();
        NameCompare name = new NameCompare();
        m.sort(array, name);
        display(array);
    }
}

class RatingCompare implements Comparator<Movie> {

    @Override
    public int compare(Movie m1, Movie m2) {
        if (m1.rating < m2.rating)           return -1;
        else if (m1.rating > m2.rating)      return 1;
        else                                 return 0;
    }
}

class NameCompare implements Comparator<Movie> {

    @Override
    public int compare(Movie movie, Movie t1) {
        return movie.name.compareTo(t1.name);
    }
}
