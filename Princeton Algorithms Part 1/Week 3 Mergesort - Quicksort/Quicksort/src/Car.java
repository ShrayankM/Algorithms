import java.util.Comparator;

public class Car {
    public String name;
    public int mileage;
    public int cost;

    Car(String name, int mileage, int cost) {
        this.name = name;
        this.cost = cost;
        this.mileage = mileage;

    }

    public static void display(Car a[]) {
        for (int i = 0; i < a.length; i++)
            a[i].getCar();
    }


    public void getCar() {
        System.out.print("Name: " + name + " Cost: " + cost + " Mileage:" + mileage + "\n");
    }

    public static void main(String args[]) {
        CostComparator c = new CostComparator();
        QuicksortObject q = new QuicksortObject();
        Car c1 = new Car("A", 23, 3000);
        Car c2 = new Car("B", 24, 2360);
        Car c3 = new Car("C", 19, 2250);
        Car c4 = new Car("D", 16, 6000);
        Car c5 = new Car("E", 17, 7000);
        Car a[] = {c1, c2, c3, c4, c5};
        q.sort(a, c);
        display(a);
    }
}



class CostComparator implements Comparator<Car> {

    @Override
    public int compare(Car c1, Car c2) {
        if (c1.mileage < c2.mileage) return -1;
        if (c1.mileage > c2.mileage) return 1;
        return 0;
    }
}
