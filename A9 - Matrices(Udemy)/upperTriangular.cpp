#include<bits/stdc++.h>
using namespace std;

struct _rmoUpper{
    int* A;
    int n, size;
    _rmoUpper(int n){
        size = (n * (n + 1))/2;
        this->n = n;
        A = new int[size + 1];
    }

    void set(int i, int j, int d){
        int index = (n * (i - 1)) - ((i - 2) * (i - 1))/2 + (j - i);
        if(i <= j)
            A[index] = d;
    }

    int get(int i, int j){
        int index = (n * (i - 1)) - ((i - 2) * (i - 1))/2 + (j - i);
        if(i <= j)
            return A[index];
        return 0;
    }
};

struct _cmoUpper{
    int* A;
    int n, size;
    _cmoUpper(int n){
        this->n = n;
        size = (n * (n + 1))/2;
        A = new int[size + 1];
    }

    void set(int i, int j, int d){
        int index = (j * (j - 1))/2 + (i - 1);
        if(i <= j)
            A[index] = d;
    }

    int get(int i, int j){
        int index = (j * (j - 1))/2 + (i - 1);
        if(i <= j)
            return A[index];
        return 0;
    }
};

void displayRMO(struct _rmoUpper T, int N){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            printf("%d ", T.get(i, j));
        }
        printf("\n");
    }
}

void displayCMO(struct _cmoUpper T, int N){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            printf("%d ", T.get(i, j));
        }
        printf("\n");
    }
}

int main(){

    int N; cin >> N;

    /**
     * TODO Storing a 2D Lower Triangular matrix using singular 1D array 
     * ! Space required for matrix (N * N) where most values are 0 
     * * Space required for array is N * (N + 1)/2 
     * ? _rmoUpper is ROW major order
     * ? _cmoUpper is COLUMN major order
     * */
    
    struct _rmoUpper array(N);
    struct _cmoUpper Array(N);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int d; cin >> d;
            array.set(i, j, d);
            Array.set(i, j, d);
        }
    }
    printf("\n");
    displayRMO(array, N);
    printf("\n");
    displayCMO(Array, N);
    return 0;
}