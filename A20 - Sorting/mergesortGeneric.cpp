#include <bits/stdc++.h>
using namespace std;


struct Car {
    int cost;
    string name;

    Car() {
        this->cost = 0;
        this->name = "Z";
    }

    Car(int cost, string name) {
        this->cost = cost;
        this->name = name;
    }

    int compare(Car c) {
        if (this -> cost < c.cost) return -1;
        else if (this -> cost > c.cost) return 1;
        else return 0;
    }
};

template<typename Car>
bool comparator(Car a, Car b) {
    return a.compare(b) < 0;
}

template<typename INTEGER>
bool comparator(int a, int b) {
    return a < b;
}

template<typename item>
struct Mergesort
{

    bool less(item a, item b)
    {
        return comparator(a, b);
    }

    void mergesort(vector<item> &arr, vector<item> &aux, int L, int MID, int H)
    {
        for (int i = L; i <= H; i++)
            aux[i] = arr[i];
            
        int i = L, j = MID + 1;
        for (int k = L; k <= H; k++)
        {
            if (i > MID)
                arr[k] = aux[j++];
            else if (j > H)
                arr[k] = aux[i++];
            else if (comparator<item>(aux[i], aux[j]))
                arr[k] = aux[i++];
            else
                arr[k] = aux[j++];
        }
        
    }

    void sort(vector<item> &arr, vector<item> &aux, int L, int H)
    {
        if (L < H)
        {
            int MID = (L + H) / 2;
            sort(arr, aux, L, MID);
            sort(arr, aux, MID + 1, H);
            mergesort(arr, aux, L, MID, H);
        }
    }

    void sort(vector<item> &arr)
    {
        vector<item> aux;
        aux.resize(arr.size());
        sort(arr, aux, 0, arr.size() - 1);
    }
};

int main()
{

    vector<int> arr = {1, 23, 4, 56, 12, 6, 89, 9};
    Mergesort<int> m;
    m.sort(arr);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";

    Car c1(100, "A"); Car c2(50, "BC"); Car c3(500, "AClass"); Car c4(250, "AZseries");
    vector<Car> arr2 = {c1, c2, c3, c4};
    
    Mergesort<struct Car> m2;
    m2.sort(arr2);

    for (int i = 0; i < arr2.size(); i++) {
        cout << "Name:" << arr2[i].name << " Cost:" << arr2[i].cost << "\n"; 
    }
    return 0;
}