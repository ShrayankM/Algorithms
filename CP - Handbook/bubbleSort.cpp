#include<cstdio>
using namespace std;

void bubbleSort(int A[], int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < (N - 1 - i); j++){
            if(A[j] > A[j + 1]){
                int T = A[j];
                A[j] = A[j + 1]; A[j + 1] = T;
            }
        }
    }
}

void display(int A[], int N){
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(){
    int A[] = {45, 4, 67, 12, 78, 3, 2, 16, 21, 79, 78, 45, 64, 55};
    int N = 14;
    bubbleSort(A, N);
    display(A, N);
    return 0;
}