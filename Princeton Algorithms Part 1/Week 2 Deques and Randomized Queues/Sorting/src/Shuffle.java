import edu.princeton.cs.algs4.StdRandom;

public class Shuffle {

    public static void RandomShuffle(int array[]) {
        for (int i = 0; i < array.length; i++) {
            int index = StdRandom.uniform(i + 1);
            exchange(array, i, index);
        }
    }

    private static void exchange(int array[], int a, int b) {
        int t = array[a];
        array[a] = array[b];
        array[b] = t;
    }

    public static void show(int array[]) {
        for (int i = 0; i < array.length; i++)
            System.out.print(array[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 1; i <= array.length; i++) {
            RandomShuffle(array);
            show(array);
        }
    }
}
