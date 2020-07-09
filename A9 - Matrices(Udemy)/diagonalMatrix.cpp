#include<bits/stdc++.h>
using namespace std;

struct Diagonal{
    int* A;
    int n;
    Diagonal(int n){
        this->n = n;
        A = new int[n + 1];
    }

    void set(int d, int i, int j){
        if(i == j)
            A[i] = d;
    }

    int get(int i, int j){
        if(i == j)
            return A[i];
        return 0;
    }
};

void displayMatrix(struct Diagonal array,int N){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << array.get(i, j) << " ";
        }
        cout << "\n";
    }
}

int main(){
    /**
     * TODO Storing a 2D diagonal matrix using singular 1D array 
     * ! Space required for matrix (N * N) where most values are 0 
     * * Space required for array is N 
     * */
    int N;
    cin >> N;
    Diagonal array(N);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int d; cin >> d;
            array.set(d, i, j);
        }
    }
    cout << "\n";
    displayMatrix(array, N);
    return 0;
}