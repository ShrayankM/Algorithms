#include<bits/stdc++.h>
using namespace std;

struct Toeplitz{
    int* A; 
    int n, size;
    Toeplitz(int n){
        this->n = n;
        size = 2 * n - 1;
        A = new int[size + 1];
    }

    void set(int i, int j, int d){
        if(i == 1){
            int index = j - i;
            A[index] = d;
        }
        else if(j == 1 && i != 1){
            int index = n + i - j - 1;
            A[index] = d;
        }
    }

    int get(int i, int j){
        if(i <= j){
            int index = j - i;
            return A[index];
        }
        else{
            int index = n + i - j - 1;
            return A[index];
        }
    }

    void display(int N){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                printf("%d ", get(i , j));
            }
            printf("\n");
        }
    }

};

int main(){

    int N; cin >> N;
    struct Toeplitz array(N);
    /**
     * TODO Storing a 2D Toeplitz matrix using singular 1D array 
     * ! Space required for matrix (N * N) where most values are 0 
     * * Space required for array is 2 * N - 1
     * ? 1st Row and 1st Column are stored
     * ? 1st Row indicates UpperTriangular elements
     * * 1st Column indicates LowerTriangular elements
     * */
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int d; cin >> d;
            array.set(i, j, d);
        }
    }
    printf("\n");
    array.display(N);
    return 0;
}