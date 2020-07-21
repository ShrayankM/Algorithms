#include<bits/stdc++.h>
using namespace std;

struct Symmetric{
    int* A;
    int n, size;
    Symmetric(int n){
        this->n = n;
        size = (n * (n + 1))/2;
        A = new int[size + 1];
    }

    void set(int i, int j, int d){
        int index = (i * (i - 1))/2 + (j - 1);
        if(i >= j)
            A[index] = d;
    }

    int get(int i, int j){
        int index = (i * (i - 1))/2 + (j - 1);
        return A[index];
    }

    void display(){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i >= j)
                    printf("%d ", get(i, j));
                else
                    printf("%d ", get(j, i));
            }
            printf("\n");
        }
    }
};

int main(){

    int N; cin >> N;
     /**
     * TODO Storing a 2D Symmetric matrix using singular 1D array 
     * ! Space required for matrix (N * N) where most values are 0 
     * * Space required for array is N * (N + 1)/2 
     * ? Array is stored same as Lower Triangular Matrix
     * */

    struct Symmetric array(N);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int d; cin >> d;
            array.set(i, j, d);
        }
    }
    printf("\n");
    array.display();
    return 0;
}