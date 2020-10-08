public class Transaction implements Comparable<Transaction> {
    public String name;
    public int amount;

    Transaction(String name, int amount) {
        this.amount = amount;
        this.name = name;
    }

    @Override
    public String toString() {
        return "(" + this.name + ") --> " + this.amount;
    }

    public static void main(String [] args) {
        Transaction t1 = new Transaction("A", 1000);
        Transaction t2 = new Transaction("B", 6000);
        Transaction t3 = new Transaction("C", 2500);
        Transaction t4 = new Transaction("D", 3000);
        Transaction [] array = {t1, t2, t3, t4};

        MaxPQ<Transaction> pq = new MaxPQ<Transaction>(array);
        pq.display();
    }

    @Override
    public int compareTo(Transaction that) {
        if (this.amount < that.amount) return -1;
        if (this.amount > that.amount) return 1;
        else                           return 0;
    }
}









