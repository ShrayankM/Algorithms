#include<bits/stdc++.h>
using namespace std;

void selection(int A[], int N){
    for(int i = 0; i < N - 1; i++){
        int j, k;
        for(j = i,  k = i; j < N; j++){
            if(A[k] > A[j])
                k = j;
        }
        swap(A[k], A[i]);
    }
}

int main(){

    int A[] = {23, 21, 12, 4, 13, 8, 76, 45, 12, 2};
    int N = sizeof(A)/sizeof(int);

    selection(A, N);
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}