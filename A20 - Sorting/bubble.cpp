#include<bits/stdc++.h>
using namespace std;

void bubble(int A[], int N){
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - i - 1; j++){
            if(A[j] > A[j + 1])
                swap(A[j], A[j + 1]);
        }
    }
}

int main(){

    int A[] = {23, 21, 12, 4, 13, 8, 76, 45, 12, 2};
    int N = sizeof(A)/sizeof(int);

    bubble(A, N);
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}