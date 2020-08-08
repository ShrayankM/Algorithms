#include<bits/stdc++.h>
using namespace std;

struct TriDiagonal{
    int* A;
    int n, size;
    TriDiagonal(int n){
        this->n = n;
        size = n + 2 * (n - 1);
        A = new int[size + 1];
    }

    void set(int i, int j, int d){
        int index;
        if(abs(i - j) <= 1){
            if(i > j)
                index = j;
            else if(i < j)
                index = (2 * n - 1) + i;
            else
                index = (n - 1 + j);
            
            A[index] = d;
        }
    }

    int get(int i, int j){
        int index;
        if(abs(i - j) <= 1){
            if(i > j)
                index = j;
            else if(i < j)
                index = (2 * n - 1) + i;
            else
                index = (n - 1 + j);
            
            return A[index];
        }
        return 0;
    }

    void display(int N){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                cout << get(i, j) << " ";
            }
            cout << "\n";
        }
    }
};

int main(){

    int N; cin >> N;
    struct TriDiagonal array(N);

    /**
     * TODO Storing a 2D Tri-Diagonal matrix using singular 1D array 
     * ! Space required for matrix (N * N) where most values are 0 
     * * Space required for array is (3 * N - 2)
     * ? Elements are stored diagonally lower-diagonal(N - 1), middle(N), upper(N - 1)
     * */

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int d; cin >> d;
            array.set(i, j, d);
        }
    }
    cout << "\n";
    array.display(N);
    return 0;
}