#include<bits/stdc++.h>
using namespace std;
struct _rmoLower{
    int* A;
    int n;
    _rmoLower(int n){
        this->n = (n * (n + 1))/2;
        A = new int[this->n + 1];
    }

    void set(int d, int i, int j){
        if(i >= j){
            int index = ((i - 1) * i)/2 + (j - 1);
            A[index] = d;
        }
    }

    int get(int i, int j){
        int index = ((i - 1) * i)/2 + (j - 1);
        if(i >= j)
            return A[index];
        return 0;
    }
};

struct _cmoLower{
    int* A;
    int n;
    int N;
    _cmoLower(int n){
        N = n;
        this->n = (n * (n + 1))/2;
        A = new int[this->n + 1];
    }

    void set(int d, int i, int j){
        if(i >= j){
            int index = N * (j - 1) - (((j - 1) * (j - 2))/2) + (i - j);
            A[index] = d;
        }
    }

    int get(int i, int j){
        int index = N * (j - 1) - (((j - 1) * (j - 2))/2) + (i - j);
        if(i >= j)
            return A[index];
        return 0;
    }
};

void displayMatrix(struct _rmoLower array, int N){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << array.get(i, j) << " ";
        }
        cout << "\n";
    }
}

void display_Matrix(struct _cmoLower array, int N){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << array.get(i, j) << " ";
        }
        cout << "\n";
    }
}

int main(){
    int N;
    cin >> N;
    /**
     * TODO Storing a 2D Lower Triangular matrix using singular 1D array 
     * ! Space required for matrix (N * N) where most values are 0 
     * * Space required for array is N * (N + 1)/2 
     * ? _rmoLower is ROW major order
     * ? _cmoLower is COLUMN major order
     * */
    
    _rmoLower array(N);
    _cmoLower Array(N);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int d; cin >> d;
            array.set(d, i, j);
            Array.set(d, i, j);
        }
    }

    displayMatrix(array, N);
    cout << "\n";
    display_Matrix(Array, N);
    return 0;
}