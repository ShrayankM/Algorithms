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

void mergesort(int A[], int N){
    int p;
    for(p = 2; p <= N; p = p * 2){
        for(int i = 0; i + p - 1 < N; i = i + p){
            int L = i, H = i + p - 1, M = (L + H)/2;
            merge(A, L, M, H);
        }
    }
    if(p/2 < N)
        merge(A, 0, p/2 - 1, N - 1);
}

int main(){

    int A[] = {23, 21, 12, 4, 13, 8, 76, 45, 1, 5};
    int N = sizeof(A)/sizeof(int);

    mergesort(A, N);
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}