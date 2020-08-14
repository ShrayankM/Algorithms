#include<bits/stdc++.h>
using namespace std;

void merge(int A[], int L, int M, int H){
    int* B = new int[H + 1];
    int k = 0; int i = L, j = M + 1;

    while(i <= M && j <= H){
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for(; i <= M; i++)
        B[k++] = A[i];
    
    for(; j <= H; j++)
        B[k++] = A[j];
    
    for(int i = L, j = 0; i <= H; i++)
        A[i] = B[j++];
}

void mergesort(int A[], int L, int H){
    if(L < H){
        int M = (L + H)/2;
        mergesort(A, L, M);
        mergesort(A, M + 1, H);
        merge(A, L, M, H);
    }
}

int main(){

    int A[] = {23, 21, 12, 4, 13, 8, 76, 45, 1, 5};
    int N = sizeof(A)/sizeof(int);

    mergesort(A, 0, N - 1);
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}